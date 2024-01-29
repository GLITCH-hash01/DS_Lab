#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* curr = *poly;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newTerm;
    }
}

void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    Term* curr = poly;
    while (curr != NULL) {
        printf("%dx^%d ", curr->coefficient, curr->exponent);
        curr = curr->next;
        if (curr != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                addTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    int coefficient, exponent, n;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coefficient, &exponent);
        addTerm(&poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coefficient, &exponent);
        addTerm(&poly2, coefficient, exponent);
    }


    printf("First polynomial: ");
    displayPolynomial(poly1);
    printf("Second polynomial: ");
    displayPolynomial(poly2);

    Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    return 0;
}
