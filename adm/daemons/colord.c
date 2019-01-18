// colord.c
// Modify By Mudring@SanJie
// Last modified by aeddy@2004-1-7
#include <ansi.h>
void create()
{
        seteuid(getuid());
}
string clean_color(string str)
{
    string prefix, suffix;
	int i;
	string  *color  =    ({ BLK,
				RED,
				GRN,
				YEL,
				BLU,
				MAG,
				CYN,
				WHT,
				HIR,
				HIG,
				HIY,
				HIB,
				HIM,
				HIC,
				HIW,
				HBRED,
				HBGRN,
				HBYEL,
				HBBLU,
				HBMAG,
				HBCYN,
				HBWHT,
				BBLK,
				BRED,
				BYEL,
				BBLU,
				BMAG,
				BCYN,
				NOR,
				BLINK });
    if (!stringp(str))
    return str;
    while (sscanf(str, "%s[%*sm%s", prefix, suffix) == 3)
    str = prefix + suffix;
    return str;
}
varargs string replace_color(string msg,int flag)
{
	msg = replace_string(msg, "$BLK$", flag?BLK:"");
	msg = replace_string(msg, "$RED$", flag?RED:"");
	msg = replace_string(msg, "$GRN$", flag?GRN:"");
	msg = replace_string(msg, "$YEL$", flag?YEL:"");
	msg = replace_string(msg, "$BLU$", flag?BLU:"");
	msg = replace_string(msg, "$MAG$", flag?MAG:"");
	msg = replace_string(msg, "$CYN$", flag?CYN:"");
	msg = replace_string(msg, "$WHT$", flag?WHT:"");
	msg = replace_string(msg, "$HIR$", flag?HIR:"");
	msg = replace_string(msg, "$HIG$", flag?HIG:"");
	msg = replace_string(msg, "$HIY$", flag?HIY:"");
	msg = replace_string(msg, "$HIB$", flag?HIB:"");
	msg = replace_string(msg, "$HIM$", flag?HIM:"");
	msg = replace_string(msg, "$HIC$", flag?HIC:"");
	msg = replace_string(msg, "$HIW$", flag?HIW:"");
	msg = replace_string(msg, "$NOR$", flag?NOR:"");
	msg = replace_string(msg, "$BLINK$", flag?BLINK:"");

        // Background color
	msg = replace_string(msg, "$BBLK$", BBLK);
	msg = replace_string(msg, "$BRED$", BRED);
	msg = replace_string(msg, "$BGRN$", BGRN);
	msg = replace_string(msg, "$BYEL$", BYEL);
	msg = replace_string(msg, "$BBLU$", BBLU);
	msg = replace_string(msg, "$BMAG$", BMAG);
	msg = replace_string(msg, "$BCYN$", BCYN);
// 77          msg = replace_string(msg, "$BWHT$", BWHT);
	msg = replace_string(msg, "$HBRED$", HBRED);
	msg = replace_string(msg, "$HBGRN$", HBGRN);
	msg = replace_string(msg, "$HBYEL$", HBYEL);
	msg = replace_string(msg, "$HBBLU$", HBBLU);
	msg = replace_string(msg, "$HBMAG$", HBMAG);
	msg = replace_string(msg, "$HBWHT$", HBWHT);
	msg = replace_string(msg, "$HBCYN$", HBCYN);
	if(flag) msg+=NOR;
	return msg;
}
// trans_color
// raw = 0, only forecolor
// raw = 1, include backround color
// raw = 2, include blink & others
string trans_color(string arg, int raw)
{
    // forecolor
    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);

    if (raw)
    {
        // Background color
        arg = replace_string(arg, "$BBLK$", BBLK);
        arg = replace_string(arg, "$BRED$", BRED);
        arg = replace_string(arg, "$BGRN$", BGRN);
        arg = replace_string(arg, "$BYEL$", BYEL);
        arg = replace_string(arg, "$BBLU$", BBLU);
        arg = replace_string(arg, "$BMAG$", BMAG);
        arg = replace_string(arg, "$BCYN$", BCYN);
        arg = replace_string(arg, "$HBRED$", HBRED);
        arg = replace_string(arg, "$HBGRN$", HBGRN);
        arg = replace_string(arg, "$HBYEL$", HBYEL);
        arg = replace_string(arg, "$HBBLU$", HBBLU);
        arg = replace_string(arg, "$HBMAG$", HBMAG);
        arg = replace_string(arg, "$HBCYN$", HBCYN);
    }

    if (raw == 2)
    {
        // special effect
        arg = replace_string(arg, "$U$", U);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$REV$", REV);
        arg = replace_string(arg, "$HIREV$", HIREV);
        arg = replace_string(arg, "$BOLD$", BOLD);
    }

    arg += NOR;
    return arg;
}

/*
type: 1 : �漴��ɫ
      2 : �漴��ɫ��ǰ��ɫ
      3 : �漴��ɫ
      4 ���漴��ɫ
blink: 1 : ��˸
*/
varargs string random_color(int type,int blink)
{
    string  *color_a  = ({  RED,
        GRN,
        YEL,
        BLU,
        MAG,
        CYN,
        HIR,
        HIG,
        HIY,
        HIB,
        HIM,
        HIC,
        HIW,
        WHT
        });

    string *color_b =   ({  BRED,
        BGRN,
        BYEL,
        BBLU,
        BMAG,
        BCYN,
        HBRED,
        HBGRN,
        HBYEL,
        HBBLU,
        HBMAG,
        HBCYN,
        HBWHT,
        });
    string co="";
    int co1,co2;
    if( blink ) co+=BLINK;

    if( type==1 ) co+=color_b[random(sizeof(color_b))];
    else
    if( type==2 ) {
    co1=random(sizeof(color_b));
    co2=random(sizeof(color_a));
    while ( co1==co2 )
    {
    co1=random(sizeof(color_b));
    co2=random(sizeof(color_a));
    }
    co+=color_b[co1]+color_a[co2];
    }
    else
    if( type == 3 ) {
    if( random(6) )
    co1=random(6);
    else co1=13;
    co+=color_a[co1];
    }
    else
    if ( type == 4 ) {
    co1=6+random(7);
    co+=color_a[co1];
    }
    else    co+=color_a[random(sizeof(color_a))];

    return co;
}

string get_color(string arg)
{
    if( strsrch(arg,BLK)!=-1 ) return BLK;
    if( strsrch(arg,RED)!=-1 ) return RED;
    if( strsrch(arg,GRN)!=-1 ) return GRN;
    if( strsrch(arg,YEL)!=-1 ) return YEL;
    if( strsrch(arg,BLU)!=-1 ) return BLU;
    if( strsrch(arg,MAG)!=-1 ) return MAG;
    if( strsrch(arg,CYN)!=-1 ) return CYN;
    if( strsrch(arg,WHT)!=-1 ) return WHT;
    if( strsrch(arg,HIR)!=-1 ) return HIR;
    if( strsrch(arg,HIG)!=-1 ) return HIG;
    if( strsrch(arg,HIY)!=-1 ) return HIY;
    if( strsrch(arg,HIB)!=-1 ) return HIB;
    if( strsrch(arg,HIM)!=-1 ) return HIM;
    if( strsrch(arg,HIC)!=-1 ) return HIC;
    if( strsrch(arg,HIW)!=-1 ) return HIW;
    if( strsrch(arg,BLINK)!=-1 ) return BLINK;
    return "";
}

string transfer_color(string arg)
{
       if( arg=="BLK" ) return BLK;
       if( arg=="RED" ) return RED;
       if( arg=="GRN" ) return GRN;
       if( arg=="YEL" ) return YEL;
       if( arg=="BLU" ) return BLU;
       if( arg=="MAG" ) return MAG;
       if( arg=="CYN" ) return CYN;
       if( arg=="WHT" ) return WHT;
       if( arg=="HIR" ) return HIR;
       if( arg=="HIG" ) return HIG;
       if( arg=="HIY" ) return HIY;
       if( arg=="HIB" ) return HIB;
       if( arg=="HIM" ) return HIM;
       if( arg=="HIC" ) return HIC;
       if( arg=="HIW" ) return HIW;
       if( arg=="HBRED" ) return HBRED;
       if( arg=="HBGRN" ) return HBGRN;
       if( arg=="HBYEL" ) return HBYEL;
       if( arg=="HBBLU" ) return HBBLU;
       if( arg=="HBMAG" ) return HBMAG;
       if( arg=="HBCYN" ) return HBCYN;
       if( arg=="HBWHT" ) return HBWHT;
       if( arg=="BBLK" ) return BBLK;
       if( arg=="BRED" ) return BRED;
       if( arg=="BYEL" ) return BYEL;
       if( arg=="BBLU" ) return BBLU;
       if( arg=="BMAG" ) return BMAG;
       if( arg=="BCYN" ) return BCYN;
       if( arg=="NOR" ) return NOR;
       if( arg=="BLINK" ) return BLINK;
       return "";
}

string random_jjww()
{
string *jjww=({
"����˯�μ������������μ��ڿ���",
"����������֣�Ӧ����ô�����",
"�����μ��������������ׯ����",
"��������Ӧ��ϲ�������������",
"���˷�ɲ����������ס���ļ��ֽ�",
"���˷�ɲ����������ס�����ڷ���",
"�����ɲ���ɳ����Ϥ�����󸣹�",
"���з�ɲ���ɳ����Ϥ��ʩ���߱�",
"����Χɽ�߹����������Ϊ���",
"�������������٣���ͷ���m������",
"�����˵ȵ�ʤ������������������",
"�˵�������ʤ�ߣ����ޱ��������",
"�ǹʵ��Ŵ�������߳����ַ���",
"�����ޱߴ󸣾ۣ��ٵ�֤�����ϵ�"
});
    return WHT"���ƣ���"+random_color(2)+jjww[random(sizeof(jjww))]+NOR+WHT+"����";
}

string convert_color( string str )      
{
        string result_str;

        result_str = str;

        result_str = replace_string(result_str, "$BLK$", BLK);
        result_str = replace_string(result_str, "$RED$", RED);
        result_str = replace_string(result_str, "$GRN$", GRN);
        result_str = replace_string(result_str, "$YEL$", YEL);
        result_str = replace_string(result_str, "$BLU$", BLU);
        result_str = replace_string(result_str, "$MAG$", MAG);
        result_str = replace_string(result_str, "$CYN$", CYN);
        result_str = replace_string(result_str, "$WHT$", WHT);
        result_str = replace_string(result_str, "$HIR$", HIR);
        result_str = replace_string(result_str, "$HIG$", HIG);
        result_str = replace_string(result_str, "$HIY$", HIY);
        result_str = replace_string(result_str, "$HIB$", HIB);
        result_str = replace_string(result_str, "$HIM$", HIM);
        result_str = replace_string(result_str, "$HIC$", HIC);
        result_str = replace_string(result_str, "$HIW$", HIW);
        result_str = replace_string(result_str, "$NOR$", NOR);

        result_str = replace_string(result_str, "$BBLK$", BBLK);
        result_str = replace_string(result_str, "$BRED$", BRED);
        result_str = replace_string(result_str, "$BGRN$", BGRN);
        result_str = replace_string(result_str, "$BYEL$", BYEL);
        result_str = replace_string(result_str, "$BBLU$", BBLU);
        result_str = replace_string(result_str, "$BMAG$", BMAG);
        result_str = replace_string(result_str, "$BCYN$", BCYN);
//323          result_str = replace_string(result_str, "$BWHT$", BWHT);
        result_str = replace_string(result_str, "$BLINK$", BLINK);
        result_str = replace_string(result_str, "__$__", "$");

        return result_str;
}
