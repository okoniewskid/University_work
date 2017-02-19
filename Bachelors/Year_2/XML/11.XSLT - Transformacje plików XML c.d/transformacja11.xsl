<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="studenci">
	  <html>
		  <body>
			  <h2>Lista studentow</h2>
			  <table border="1">
				  <xsl:for-each select="student">
					<xsl:sort select="@plec"/>	
					<xsl:sort select="nazwisko"/>
					<tr>
					<td><xsl:value-of select="nazwisko"/>
					<xsl:text> </xsl:text>
					<xsl:value-of select="imie"/>
					<xsl:text> grupa: </xsl:text>
					<xsl:value-of select="grupa"/>
					</td>
					</tr>
				</xsl:for-each>
			</table>
		  </body>
	  </html>
  </xsl:template>
</xsl:stylesheet>
