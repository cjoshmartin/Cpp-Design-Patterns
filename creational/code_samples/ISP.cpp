// Interface Segregation Pricinciple

// No Client should be forced to depend on methods it does not use


struct Document;

struct  IMachine
{
    virtual void print(std::vector<Document*> doc) = 0;
    virtual void scan(std::vector<Document*> doc) = 0;
    virtual void fax(std::vector<Document*> doc) = 0;
};

struct MFP : IMachine
{
    void  print(std::vector<Document*> doc) override;
    void  scan(std::vector<Document*> doc) override;
    void  fax(std::vector<Document*> doc) override;
};