#pragma once
#include<iostream>
#include<unordered_map>
enum Nucleotide {																											// Nucleotide
	A = 0b00000000,
	G = 0b00000001,
	C = 0b00000010,
	T = 0b00000011
};

class RNA {																													// Class RNA
	friend class jab;
	class jab {																												// Class jab
	private:
		size_t jab_index;
		RNA* jab_RNA;
	public:
		jab(RNA* RNA_received, size_t index_nucleotide); 																	// jab Constructor
		jab& operator= (Nucleotide Nucleotide_add);																			// jab Operator =
		operator Nucleotide() const;																						// Nucleotide_type
	};
private:
	size_t RNA_size;
	size_t* RNA_arr;
public:
	RNA();																													// Constructor
	RNA(Nucleotide Nucl, size_t size);																						// Constructor
	RNA(const RNA& RNA_2);																									// Copy constructor
	~RNA();																													// Destructor
	size_t RNA_length();																									// RNA_length
	RNA& operator= (const RNA& RNA_2);																						// Operator =
	jab operator[] (size_t index);																							// Operator []
	Nucleotide operator[] (size_t index) const;																				// Operator []
	friend std::ostream& operator<< (std::ostream& out, const RNA& RNA);													// Operator <<
	RNA operator! () const;																									// Operator !
	bool operator== (const RNA& RNA_2) const;																				// Operator ==
	bool operator!= (const RNA& RNA_2) const;																				// Operator !=
	bool RNA_complementarity(const RNA& RNA_2) const;																		// RNA_complementarity
	size_t RNA_cardinality(Nucleotide Nucl) const;																			// RNA_cardinality
	RNA operator+ (const RNA& RNA_2) const;																					//* Operator +
	void RNA_trim(size_t last_index);																						// RNA_trim
	RNA RNA_split(size_t last_index) const;																					// RNA_split
	std::unordered_map < Nucleotide, size_t, std::hash<size_t> > RNA_cardinality() const;									// unordered_map
};