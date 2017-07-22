// Interface Segregation Pricinciple

// No Client should be forced to depend on methods it does not use


struct Document;

struct IPrinter {
    virtual void print(std::vector<Document*> doc) = 0;
};
struct IScanner{
        virtual void scan(std::vector<Document*> doc) = 0;
};

struct IFax {
    virtual void fax(std::vector<Document*> doc) = 0;
};



// using the interfaces

struct  Print : IPrinter
{
    void print(std::vector<Document*> docs) override;
};

struct Scanner : IScanner
{
    void  scan(std::vector<Document*> doc) override;
};


struct  Fax : IFax
{
    void  fax(std::vector<Document*> doc) override;
};