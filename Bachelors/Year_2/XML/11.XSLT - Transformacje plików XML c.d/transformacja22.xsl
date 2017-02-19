<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="studenci">
	  <html>
		  <body>
			  <h2>Lista studentow</h2>
			  <ol>
				  <xsl:for-each select="student">
				 
					<li>
					<xsl:choose>
						<xsl:when test="@plec='k'">
							<span style="color:red">
							<xsl:value-of select="nazwisko"/>
							<xsl:text> </xsl:text>
							<xsl:value-of select="imie"/>
						</span></xsl:when>
						<xsl:when test="@plec='m'">
							<span style="color:blue">
							<xsl:value-of select="nazwisko"/>
							<xsl:text> </xsl:text>
							<xsl:value-of select="imie"/>
						</span></xsl:when>
					</xsl:choose>
					<xsl:text> grupa: </xsl:text>
					<xsl:value-of select="grupa"/>
					</li>
				  
				</xsl:for-each>
				</ol>
		  </body>
	  </html>
  </xsl:template>
</xsl:stylesheet>
