#ifndef EXPORT_SYNTAXVIEW_H_H_
#define EXPORT_SYNTAXVIEW_H_H_

class StyleContextBase {
public:
    virtual void Complete() = 0;
    virtual bool More() const = 0;
    virtual void Forward() = 0;

    virtual int GetStat() = 0;

    virtual void Forward(int n) = 0;
    virtual void ForwardBytes(int n) = 0;
    virtual void ChangeState(int state) = 0;
    virtual void SetState(int state) = 0;
    
    virtual void ForwardSetState(int state) = 0;
    virtual int LengthCurrent() const = 0;
    virtual int GetRelative(int n) = 0;
    
    virtual int GetRelativeCharacter(int n) = 0;
    virtual bool Match(char c) const = 0;
    virtual bool Match(char c1, char c2) const = 0;
    virtual bool Match(const char *s) = 0;
    virtual bool MatchIgnoreCase(const char *s) = 0;
    virtual bool MatchIgnoreCase2(const char *s) = 0;
    virtual void GetCurrent(char *s, unsigned int len) = 0;
    virtual void GetCurrentLowered(char *s, unsigned int len) = 0;
};

typedef void (__stdcall *pfnColouriseTextProc)(
    int initStyle,
    unsigned int startPos,
    const char *data,
    int length,
    StyleContextBase *sc
    );

void __stdcall RegisterSyntaxProc(const char *label, pfnColouriseTextProc pfn);
#endif //EXPORT_SYNTAXVIEW_H_H_