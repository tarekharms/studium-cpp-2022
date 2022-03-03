//
//  OneByOneMatrix.h
//  CopyOnWrite
//
//  Created by clink on 17/05/16.
//  Copyright (c) 2016 HSEL. All rights reserved.
//

#ifndef __CopyOnWrite__OneByOneMatrix__
#define __CopyOnWrite__OneByOneMatrix__


class OneByOneMatrix {
  
  int m_value;
  
  int m_referenceCounter;         // refcounting
  static int s_instanceCounter;   // assertions
public:
  OneByOneMatrix();
  explicit OneByOneMatrix(int initialValue);
  OneByOneMatrix(const OneByOneMatrix&);
  ~OneByOneMatrix();
  
  explicit operator int();
  OneByOneMatrix operator+(const OneByOneMatrix & other);
  OneByOneMatrix& operator ++(int);
  bool operator==(const OneByOneMatrix& other);
  bool operator!=(const OneByOneMatrix& other);
  
  friend class OneByOneMatrix_CopyOnWrite;
  static bool instanceCountExceeds(int max);  // assertions
};

// imagine this class as an abstraction for very large matrices

class LargeCowMatrix {
  
};


#endif /* defined(__CopyOnWrite__OneByOneMatrix__) */
