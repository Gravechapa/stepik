#include <iostream>
#include <map>
class SmallAllocator {
private:
    char Memory[1048576];
    void* const limit = &Memory + sizeof(Memory);
    std::map<void*, size_t> allocedMemory;
public:
    void *Alloc(unsigned int Size) 
    {
        if (allocedMemory.empty())
            {
                if (&Memory + Size <= limit)
                    {
                        allocedMemory.insert(std::pair<void*, size_t>(&Memory, Size));
                        return &Memory;
                    }
                else
                    return NULL;
            }
        else
            {
                for (auto it = allocedMemory.begin(); it != --allocedMemory.end(); it++)
                    {
                        void *ptr = it->first + it->second + 1;
                        auto nextIt = it;
                        ++nextIt;
                        if(ptr + Size < nextIt->first)
                            {
                                allocedMemory.insert(std::pair<void*, size_t>(ptr, Size));
                                return ptr;
                            }
                    }
                auto it = --allocedMemory.end();
                void* ptr = it->first + it->second + 1;
                if (ptr + Size <= limit)
                    {
                        allocedMemory.insert(std::pair<void*, size_t>(ptr, Size));
                        return ptr;
                    }
                else
                    return NULL;
            }
    };
    void *ReAlloc(void *Pointer, unsigned int Size) 
    {
        std::map<void*, size_t>::iterator  it= allocedMemory.find(Pointer);
           if( it != allocedMemory.end() )
                {
                    auto nextIt = it;
                    ++nextIt;
                    if (it->first + Size < nextIt->first)
                        {
                            it->second = Size;
                            return Pointer;
                        }
                    else
                        {
                            void *ptr = this->Alloc(Size);
                            void *buffPtr = ptr;
                            for (void* i = it->first; i <= it->first + it->second; i++)
                                {
                                    *(char*)buffPtr = *(char*)i;
                                    ++buffPtr;
                                }
                            this->Free(it->first);
                            return ptr;
                        }
                }
            else
                return NULL;

    };
    void Free(void *Pointer) 
    {
        std::map<void*, size_t>::iterator  it= allocedMemory.find(Pointer);
            if( it != allocedMemory.end() )
                allocedMemory.erase(it);
    };
};

int main()
{
    SmallAllocator A1;
    int * A1_P1 = (int *) A1.Alloc(sizeof(int));
    A1_P1 = (int *) A1.ReAlloc(A1_P1, 2 * sizeof(int));
    A1.Free(A1_P1);
    SmallAllocator A2;
    int * A2_P1 = (int *) A2.Alloc(10 * sizeof(int));
    for(unsigned int i = 0; i < 10; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < 10; i++) if(A2_P1[i] != i) std::cout << "ERROR 1" << std::endl;
    int * A2_P2 = (int *) A2.Alloc(10 * sizeof(int));
    for(unsigned int i = 0; i < 10; i++) A2_P2[i] = -1;
    for(unsigned int i = 0; i < 10; i++) if(A2_P1[i] != i) std::cout << "ERROR 2" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 3" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, 20 * sizeof(int));
    for(unsigned int i = 10; i < 20; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < 20; i++) if(A2_P1[i] != i) std::cout << "ERROR 4" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 5" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, 5 * sizeof(int));
    for(unsigned int i = 0; i < 5; i++) if(A2_P1[i] != i) std::cout << "ERROR 6" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 7" << std::endl;
    A2.Free(A2_P1);
    A2.Free(A2_P2);
}
