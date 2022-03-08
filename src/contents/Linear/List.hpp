namespace DataStructure::Query::Linear
{
    template <class T>
    class List
    {
    private:
        T* _first;
        unsigned int _size;

    public:
        List() {
            this->_first = nullptr;
            this->_size = 0;
        }
        ~List() {}

        unsigned int size() const { return this->_size; }
        void size(const int newSize) { this->_size = newSize; }


        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position)

            void find(T data);
        void findAt(int position);
    };
}