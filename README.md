<!DOCTYPE html>
<html>

<table border="1" cellspacing="0" cellpadding="5">
      <tbody>
        <tr> 
          <td width="114" align="center"><p><strong>TOPICS</strong><br>
              <strong>and NOTES</strong></p></td>
          <td width="264" align="center"><strong>Key Subtopics<br>
          </strong></td>
          <td width="144" align="center"><strong>Sample 
                Code</strong></td>
        </tr>
    <tr> 
      <td width="114" height="40"><p><a href="https://github.com/william1357chen/CS2124-OOP/blob/master/Python%20to%20C%2B%2B/DIfference%20between%20Python%20and%20C%2B%2B.md">Python to C++</a></p>
      <p><font size="3"><a href="./README.md">Basic C++</a></font></p></td>
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
      <td height="41"><font size="3"><a href="https://github.com/william1357chen/CS2124-OOP/blob/master/Classes/Class%20Basics.md">Classes</a></font></td>
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
      <td><p><font size="3"><a href="https://github.com/william1357chen/CS2124-OOP/blob/master/Pointers/pointers.md">Pointers</a></font></p>
      <p><a href="https://github.com/william1357chen/CS2124-OOP/blob/master/Classes/Composition%20and%20Association.md">Composition 
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
