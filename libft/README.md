<h1><b><em>LIBFT (grade : 125)</em></b></h1>
<div align="center"><br>
  <img src="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" alt="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" width="400" height="200">
</div>
<body>
	
  <p><b>After passing through the Piscine this was my first project.</b></p>
  <p>In this library you will find the following functions, working as intended: </p>
  <p><i>✓bzero ✓calloc ✓memset ✓memmove ✓memchr ✓memcmp ✓memcpy </i></p>
  <p><i>✓isalpha ✓isdigit ✓isalnum ✓isascii ✓isprint ✓toupper ✓tolower ✓atoi ✓itoa </i></p>
  <p><i>✓strlen ✓strlcpy ✓strchr ✓strrchr ✓strlcat ✓strncmp ✓strnstr ✓strdup ✓substr ✓strjoin ✓strtrim ✓split </i></p>
  <p><i>✓strmapi ✓striteri ✓putchar_fd ✓putchar_fd ✓putstr_fd ✓putendl_fd ✓putnbr_fd </i></p>				
  <p>And the bonus ones:</p>	  
  <p><i>✓lstnew ✓lstnew ✓lstsize ✓lstlast ✓lstadd_back ✓lstdelone ✓lstclear ✓lstiter ✓lstmap </i></p>	
  <p></p>
<p>I also ran the three testers i found online, the <em><b>Unit Tester</b></em> (made by: <i>alelievr</i>), the <em>LibftTester</em>, a.k.a <em><b>Tripouille tester</b></em> (made by : <i>jgambard</i>) and the <em><b>Libft War Machine</b></em> (made by : <i>y3ll0w42</i>)[links below], and this is the ouput:
<div align="center"><br>
  <img src="https://user-images.githubusercontent.com/99777188/155604500-d36bd410-714e-4d83-a632-a2c7a1aee0b4.jpg" alt="https://user-images.githubusercontent.com/99777188/155604500-d36bd410-714e-4d83-a632-a2c7a1aee0b4.jpg" width="1200" height="775">
</div>
We can see that its missing ft_memmcpy function in the Unit tester, the reason is that <b>back in the days</b> that this tester was made, <u>memccpy was a mandatory function</u>, and nowadays <b>its not even asked for.</b> I also found to be very usefull to run the 3 testers, since i passed in the unit one and after that i got KOs on Tripouille, and after i got everything right on Tripouille i still got one KO on War Machine. This is not due to one being better then the other, since one collegue of mine did a different order and got the same thing, so i can conclude that what is happening is that they <u><b>complement</b> each other very well</u>, and they test different aspect limits of the code on each test.</p>
<div align="center"><br>
  <img src="https://user-images.githubusercontent.com/99777188/155854781-cca1bf7a-4372-4a45-b95d-61c401ce6f63.png" alt="https://user-images.githubusercontent.com/99777188/155854781-cca1bf7a-4372-4a45-b95d-61c401ce6f63.png" width="1100" height="210">
</div>
<p></p>
<p></p>
<p><i>links of the testers:<i></p>
<p>Unit tester: https://github.com/alelievr/libft-unit-test</p>
<p>Tripouille tester: https://github.com/Tripouille/libftTester</p>
<p>War Machine tester: https://github.com/y3ll0w42/libft-war-machine</p>
</body>
</html>
