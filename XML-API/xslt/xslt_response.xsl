<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

	<xsl:template match="/">
		<a href="form.php">Back</a>
		<table style="border-collapse: collapse">
			<xsl:apply-templates/>
		</table>
	</xsl:template>
	
	<xsl:template match="NEWSPAPER">
		<tr style="border: 2px dotted black;">
			<td style="font-family: 'Chelsea Market', cursive">
				<xsl:value-of select="./@*"/>
			</td>
			<xsl:for-each select="./ARTICLE">
				<td>					
					<xsl:for-each select="./@*">						
						<p><xsl:value-of select="."/></p>						
					</xsl:for-each>
				</td>
				<xsl:choose>
					<xsl:when test="@DESCRIPTION='News'">
						<td style="background:#def;border: 1px solid gray;">
							<xsl:apply-templates/>
						</td>
					</xsl:when>
					<xsl:otherwise>
						<td style="background:#fc9;border: 1px solid gray;">
							<xsl:apply-templates/>
						</td>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:for-each>
		</tr>
	</xsl:template>
	
	<xsl:template match="HEADING">
		<h3><xsl:value-of select="./TEXT"/></h3>		
	</xsl:template>

	<xsl:template match="STORY">
		<div>
			<xsl:for-each select="./TEXT">
				<p><xsl:value-of select="."/></p>
			</xsl:for-each>
		</div>
	</xsl:template>	
	
</xsl:stylesheet>   