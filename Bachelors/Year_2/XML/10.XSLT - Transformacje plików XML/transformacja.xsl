<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" doctype-system="about:legacy-compat" encoding="UTF-8"/>
  <xsl:template match="studenci">
	  <html>
		  <head><title>lab10</title></head>
		  <body>
			  <h2>Lista studentow</h2>
			  <ol>
					<xsl:for-each select="student">
						<li>	
						<u><xsl:value-of select="nazwisko"/> </u>
						
						<xsl:text> </xsl:text>
						
						<xsl:if test="@plec='k'">
						<span style="color:red">
						<xsl:value-of select="imie"/></span></xsl:if>
						
						<xsl:if test="@plec='m'">
						<span style="color:blue">
						<xsl:value-of select="imie"/></span></xsl:if>
						
						<xsl:text> grupa: </xsl:text>
						<xsl:value-of select="grupa"/>
					</li>			  
					</xsl:for-each>
				</ol>
		  </body>
	  </html>
  </xsl:template>
</xsl:stylesheet>
