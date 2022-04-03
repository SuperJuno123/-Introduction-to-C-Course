
#include <cmath>

class Vector3D {
private:
	int x;
	int y;
	int z;
public:
	Vector3D(int _x = 0, int _y = 0, int _z = 0) {
		x = _x;
		y = _y;
		z = _z;
	}
	Vector3D(Vector3D const& vect) {
		x = vect.x;
		y = vect.y;
		z = vect.z;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	int get_z() {
		return z;
	}
	void set_x(int _x) {
		x = _x;
	}
	void set_y(int _y) {
		x = _y;
	}
	void set_z(int _z) {
		x = _z;
	}
	double norm() {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(x, 2));
	}
	Vector3D operator +(Vector3D vect) {
		return Vector3D(this->get_x() + vect.get_x(), this->get_y() + vect.get_y(), this->get_z() + vect.get_z());
	}
	Vector3D operator +(const int scalar) {
		return Vector3D(this->get_x() + scalar, this->get_y() + scalar, this->get_z() + scalar);
	}
	Vector3D operator -(Vector3D vect) {
		return Vector3D(this->get_x() - vect.get_x(), this->get_y() - vect.get_y(), this->get_z() - vect.get_z());
	}
	Vector3D operator -(const int scalar) {
		return Vector3D(this->get_x() - scalar, this->get_y() - scalar, this->get_z() - scalar);
	}
	Vector3D operator *(const int scalar) {
		return Vector3D(this->get_x() * scalar, this->get_y() * scalar, this->get_z() * scalar);
	}
	Vector3D operator *(Vector3D vect) {
		// fixed implementation for 3D case
		int _x = this->get_y() * vect.get_z() - this->get_z() * vect.get_y();
		int _y = -(this->get_x() * vect.get_z() - this->get_z() * vect.get_x());
		int _z = this->get_x() * vect.get_y() - this->get_y() * vect.get_x();
		return Vector3D(_x, _y, _z);
	}
	friend std::ostream& operator<< (std::ostream&, const Vector3D&);
};
std::ostream& operator << (std::ostream& os, const Vector3D& vect) {
	return os << "[" << vect.x << ", " << vect.y << ", " << vect.z << "]";
}
Vector3D operator*(const int scalar, Vector3D& vect)
{
	return vect * scalar;
}