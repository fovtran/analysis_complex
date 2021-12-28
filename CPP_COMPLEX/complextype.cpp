template <> class complex<double> {
public:
    constexpr complex(
    double _RealVal = 0,
    double _ImagVal = 0);

constexpr complex( const complex<double>& complexNum);
constexpr explicit complex( const complex<long double>& complexNum);
};
