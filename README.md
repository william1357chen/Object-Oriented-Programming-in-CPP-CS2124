# Introduction to Object Oriented Prorgamming in C++
Welcome! This is the reorganized notes for Intro to Object Oriented Programming in C++ CS-2124 taught by Professor Sterling. Additionally, The first topic was added for introducing the concept of Object Oriented Programming and its main principles.

## Object Oriented Programming in a Nutshell
<!DOCTYPE html>
<html>
<table align="center" cellspacing="0" cellpadding="5">
      <tbody>
        <tr> 
          <td width="114" align="center"><p><strong>TOPICS</strong><br>
              <strong>and NOTES</strong></p></td>
          <td width="114" align="center"><strong>Key Subtopics<br>
          </strong></td>
        </tr>
    <tr> 
      <td width="114" height="40"><p><a href="./OOP%20Simplified/OOP%20Simplified.md">What is OOP</a></p>
      </td>
      <td width="264" height="40"><ul>
          <li>Encapsulation</li>
          <li>Abstraction</li>
          <li>Inheritance</li>
          <li>Polymorphism</li>
        </ul></td>
      <td width="144"><ul>
      </td>
    </tr>
    </tbody>
</table>
</html>

## CS 2124 Notes

<html>
<table cellspacing="0" cellpadding="5">
      <tbody>
        <tr> 
          <td width="23%" align="center"><p><strong>TOPICS</strong><br>
              <strong>and NOTES</strong></p></td>
          <td width="52%" align="center"><strong>Key Subtopics<br>
          </strong></td>
          <td width="23%" align="center"><strong>Sample 
                Code</strong></td>
        </tr>
    <tr> 
      <td width="114" height="40"><p><a href="./Python%20to%20C++/Difference%20between%20Python%20and%20C++.md">Python to C++</a></p>
      <p><font size="3"><a href="./Basic%20C++/Basic%20Syntax.md">Basic C++</a></font></p></td>
      <td width="264" height="40"><ul>
          <li>Simple program</li>
          <li>Loops</li>
          <li>Conditions</li>
          <li>File I/O</li>
          <li>Vectors</li>
          <li>Structs</li>
          <li>Functions / parameter passing</li>
        </ul></td>
      <td width="144"><ul>
          <li>Reading in a file</li>
          <li>How <em>NOT</em> to read a file</li>
          <li>Reading a file into a vector</li>
          <li>Vector of objects that contain vectors </li>
        </ul></td>
    </tr>
    <tr>
      <td height="41"><font size="3"><a href="./Classes/Class%20Basics.md">Classes</a></font></td>
      <td height="41"><ul>
          <li>Member variables and functions</li>
        <li>Constructors. </li>
        <li>Const functions. </li>
        <li>Separating the class definition from the member function definitions.</li>
      </ul></td>
      <td><ul>
          <li>A simple Date Class</li>
        <li>Composition and association</li>
        <li>Dynamic array of pointers to objects.</li>
      </ul></td>
    </tr>
    <tr>
      <td ><p><font size="3"><a href="./Pointers/pointers.md">Pointers</a></font></p>
      <p><a href="./Classes/Composition%20and%20Association.md">Composition 
      and Association</a></p></td>
      <td><ul>
          <li>address/location</li>
        <li>pointer variables</li>
        <li>address-of operator</li>
        <li>dereferencing operator</li>
        <li>pointer arithmetic</li>
        <li>new/delete</li>
      </ul></td>
      <td><ul>
          <li>Intro to addresses andpointers</li>
      </ul></td>
    </tr>
    <!--
    <tr> 
      <td>
        <a href="../LectureNotes/06.Big3.html">Copy Control </a><br>
        <a href="../LectureNotes/06b.Vector.html">Implementing the Vector</a>
      </td>
      <td><ul>
        <li>Destructor
          </li>
        <li>copy constructor</li>
        <li>assignment operator</li>
      </ul>      </td>
      <td><ul>
          <li>Need for copy constructor.</li>
          <li>Vector class.</li>
        </ul></td>
    </tr>
    <tr>
      <td>
        <a href="../LectureNotes/10.SeparateCompilation.html">Separate Compilation<a><br>
        <a href="../LectureNotes/10.SeparateCompilationNamespaces.html">Namespaces</a><br>
        <a href="../LectureNotes/04.IncludeGuard.html">Include Guards</a><br>
        <a href="../LectureNotes/03b.ForwardDeclarations.html">Cyclic Association</a>
      </td>
      <td><ul>
          <li>header files and implementation files.</li>
        <li>include guard: #ifndef, #define and, #endif</li>
      </ul></td>
      <td><ul>
          <li>The class Date using separate compilation and a namespace.</li>
      </ul></td>
    </tr>
    <tr>
      <td><a href="../LectureNotes/05.OverloadingOperators.html">Operator overloading</a></td>
      <td><ul>
          <li>Why?</li>
        <li>Operator expressions as function calls.</li>
        <li> I/O operators</li>
        <li>Comparison operators.</li>
        <li>Friends</li>
        <li>What you can / can't do with operator overloading. <br>
        </li>
      </ul></td>
      <td><ul>
          <li>Overloading operators for the Date class</li>
        </ul></td>
    </tr>
    <tr>
      <td height="63"><p><font size="3"><a href="../LectureNotes/04.Inheritance.html">Inheritance</a></font></p></td>
      <td height="63"><ul>
          <li>Simple public inheritance. </li>
        <li>Protected access. </li>
        <li>Polymorphism. </li>
        <li>Virtual mechanism and virtual methods. </li>
        <li>Pure virtual methods and abstract classes.</li>
        <li>Multiple Inheritance</li>
      </ul></td>
      <td><ul>
          <li>Basic inheritance</li>
        <li>Order of constructors and destructors.</li>
        <li>Polymorphism</li>
        <li>Abstract Classes</li>
      </ul></td>
    </tr>
    <tr> 
      <td><font size="3"><a href="../LectureNotes/LinkedList.html">Linked 
        Lists</a></font></td>
      <td><ul>
        <li>Implement a toolkit for a singly linked list.</li>
      </ul></td>
      <td><ul>
          <li>Linked List Toolkit</li>
        </ul></td>
    </tr>
    <tr> 
      <td><font size="3"><a href="../LectureNotes/Recursion.htm">Recursion</a></font></td>
      <td>        <ul>
          <li>Understanding recursive code</li>
          <li>Writing recursive functions </li>
        </ul></td>
      <td><ul>
          <li>Simple examples</li>
          <li>Binary Search</li>
          <li>Linked List toolkit using recursion.</li>
        </ul></td>
    </tr>
    <tr> 
      <td><a href="../LectureNotes/STL.html">STL - Standard Template Library</a></td>
      <td><ul>
          <li>Containers (vector and <a href="https://cse.engineering.nyu.edu/jsterling/cs2124/LectureNotes/STLlist.html">list</a>),          </li>
          <li>Iterators</li>
          <li>Generic algorithms</li>
        </ul></td>
      <td><ul>
          <li>Some examples using the STL vector and list.</li>
        </ul></td>
    </tr>
    <tr>
      <td><a href="../LectureNotes/Exceptions-assertions.html">Exceptions and Assertions</a></td>
      <td>&nbsp;</td>
      <td>&nbsp;</td>
    </tr>
    -->
  </tbody>
</table>
</html>
