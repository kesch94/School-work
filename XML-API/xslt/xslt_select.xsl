<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:template match="/">
        <form method='post' action='responseXSLT.php'>
            <select name='paper'>
                <xsl:apply-templates/>
            </select>
            <button>send</button>
        </form>
    </xsl:template>
    <xsl:template match="NEWSPAPER[@TYPE='Morning_Edition']">
        <option value='Morning_Edition'>
            <xsl:value-of select="@NAME">
            </xsl:value-of>
        </option>
    </xsl:template>
    <xsl:template match="NEWSPAPER[@TYPE='Evening_Edition']">
        <option value='Evening_Edition'>
            <xsl:value-of select="@NAME">
            </xsl:value-of>
        </option>
    </xsl:template>
</xsl:stylesheet>             