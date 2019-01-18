//Cracked by Roath
// rankd.c

#include <ansi.h>

//descriptions...

//note, be careful with the size of this list, dx increases as n^3. 
string *dx_level_desc = ({
        BLU "�����;" NOR, //in unit of year 
        BLU "�ŵ���ϲ" NOR, //1x2=2   
        BLU "�������" NOR, //8x2=16
        BLU "��ͨ����" NOR, //27x2=56    
        HIB "����Ѿ�" NOR, //64x2=128
        HIB "Ԫ�����" NOR, //125x2=250
        HIB "�����ȹ�" NOR, //216x2=432    
        HIB "һ��ǧ��" NOR, //343x2=686
        CYN "���ߵ�¡" NOR, //512x2=1024
        HIR "�����ֻ�" NOR, 
        CYN "ϼ�ٷ���" NOR, //1000x2=2000
        CYN "��������" NOR, //1331x2=2662    
        HIY "��̥����" NOR, 
//������2002-07-03 Cigar@sjsh_sk ���ӣ���ȫ�����ϼ��㹫ʽ��
        HIY "�������" NOR, 
        HIY "�˶�ʤ��" NOR, 
        HIY "���᳤��" NOR, 
        HIG "���¾���" NOR, 
        HIG "��ͨ���" NOR, 
        HIG "��������" NOR, 
        HIG "����ٵ�" NOR, 
        HIC "���춯��" NOR, 
        HIC "������˫" NOR, 
        HIC "��֤���" NOR, //2197x2=4394    
        HIC "��豹���" NOR, //2744x2=5688 
        HIW "��Ⱥ����" NOR, 
        HIW "��ų���" NOR, 
        HIW "���˺�һ" NOR, //3375x2=6750
        HIW "��������" NOR
});

string *fali_level_desc = ({
        BLU "���߷���" NOR, //    
        BLU "�����仯" NOR, //1x40=40
        BLU "��������" NOR, //4x40=160
        HIB "���Ƽ���" NOR, //9x40=360   
        HIB "�����û" NOR, //16x40=640
        HIB "Ԥ֪����" NOR, //25x40=1000
        HIB "�������" NOR, //36x40=1440    
        CYN "���绽��" NOR, //49x40=1960
        CYN "������ɽ" NOR, //64x40=2560    
        CYN "���ǻ���" NOR, //81x40=3240
        CYN "��������" NOR, //100x40=4000
//������2002-07-03 Cigar@sjsh_sk ���ӣ���ȫ�����ϼ��㹫ʽ��
        HIY "�������" NOR, 
        HIY "��ɽ����" NOR, 
        HIY "���ò�Ϣ" NOR, 
        HIR "�һ����" NOR, 
        HIR "��ԭ�һ�" NOR, 
        HIR "˲Ϣ���" NOR, 
        HIG "�������" NOR, 
        HIG "��󴻢��" NOR, 
        HIG "����ɽ��" NOR, 
        HIG "���츲��" NOR, 
        HIG "͵�컻��" NOR, 
        HIC "��������" NOR, //121x40=4840    
        HIC "�任Ī��" NOR, //144x40=5760
        HIW "Ψ�Ҷ���" NOR, 
        HIW "��ٲ���" NOR, 
        HIW "�������" NOR, 
        HIW "�����ޱ�" NOR  //169x40=6760
});

string *exp_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "�����ž�" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��֪һ��" NOR,
        YEL "��������" NOR,
        YEL "������" NOR,
        HIY "����С��" NOR,
        HIY "����Ѿ�" NOR,
        HIM "�������" NOR,
        HIM "��Ȼ����" NOR,
        HIR "�������" NOR,
        HIR "�������" NOR,
        MAG "����似" NOR,
        MAG "�����뻯" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "�Ƿ��켫" NOR,
        HIC "������˫" NOR,
        HIC "һ����ʦ" NOR,
        HIC "������" NOR,
        HIC "��ɲ�" NOR,
        HIR "������ħ" NOR,
        HIR "��������" NOR,
        YEL "���컯��" NOR,
        YEL "�޼�����" NOR,
        HIW "�ݺ����" NOR,
        HIW "�޵��칬" NOR,
        HIW "Ц������" NOR,
        HIW "�ڷ�֮��" NOR
});

string describe_dx(int value)
{
        int grade, two_year, n;
        
        two_year = value/4000;
        for(grade=0; grade<sizeof(dx_level_desc); grade++)
//sizeof(dx_level_desc)
        {
                n = (grade+1)*(grade+1)*(grade+1);
          if (grade > 28) n = (grade+1)*(grade+1)*(grade+1)*(grade+1);
                if( two_year<n ) break;
        }
        if( grade>=sizeof(dx_level_desc) ) grade=sizeof(dx_level_desc)-1;
        return dx_level_desc[grade];
}

int grade_dx(string desc)
{
        int grade, n;

        for(grade=0; grade<sizeof(dx_level_desc); grade++) 
        {
                n = grade;
                if ( dx_level_desc[grade] == desc )
                        return n;
        }
        return 0;
}

string describe_exp(int value)
{
        int grade, lvl , n;
        
        lvl = (value*2)/675;
        //note, this is to make ��ɲ� requires 2700k combat_exp,
        //which also means player can learn skill level to 300.

        for(grade=0; grade<sizeof(exp_level_desc); grade++) 
        {
                n = (grade+1)*(grade+1)*(grade+1);
                   if (grade > 15) n = (grade+1)*(grade+1)*(grade+1)*(grade+1);
                if( lvl<n ) break;
        }
        if( grade>=sizeof(exp_level_desc) ) grade=sizeof(exp_level_desc)-1;
        return exp_level_desc[grade];
}

int grade_exp(string desc)
{
        int grade, n;

        for(grade=0; grade<sizeof(exp_level_desc); grade++) 
        {
                n = grade;
                if ( exp_level_desc[grade] == desc )
                        return n;
        }
        return 0;
}

string describe_neili(int value)
{
        int year, sixty, left;
        string line;
        
        year = value/100;
        sixty = year/60;
        left = year - sixty*60;

        if( year <= 0 )
        {
                line = HIB "����һ��" NOR;
                return line;
        }
        
        if(sixty > 0 )
        {
                if ( left != 0 )
                { 
                        line = HIW + chinese_number(sixty) + "����" + NOR + "��" +  HIR + chinese_number(left) + "��" + NOR;
                }
                else 
                {
                        line = HIW + chinese_number(sixty) + "����"  + NOR;     
                }               
        }
        else 
                line = HIR + chinese_number(year)+"��" + NOR;

        return line;
}

string describe_fali(int value)
{
        int grade, lvl, n;

        //in unit of 40, increase by n^2.
        lvl=value/20;
        for(grade=0; grade<sizeof(fali_level_desc); grade++) 
        {
                n=(grade+1)*(grade+1);
                if( lvl<n ) break;
        }
        if( grade>=sizeof(fali_level_desc) ) grade=sizeof(fali_level_desc)-1;
        return fali_level_desc[grade];
}
 
int grade_fali(string desc)
{
        int grade;

        for(grade=0; grade<sizeof(fali_level_desc); grade++) 
        {
                if ( (string)fali_level_desc[grade] == desc )
                        return grade;
        }
        return 0;
}

string query_description(int type)
{
    int i;
    string *level_desc;
    string line = "";
    
    if(type==0) level_desc = dx_level_desc;
    else if(type==1) level_desc = exp_level_desc;
    else level_desc = fali_level_desc;
    
    for(i=0; i<sizeof(level_desc); i++)
    {
        line += level_desc[i] + "    ";
        if( (i%4)==3 ) line += "\n";
    }
    
    return line;
}

string _query_rank(object ob);

string query_rank(object ob)
{
    string rank=_query_rank(ob);
    string s1,s2,s3;
    int len, len1, len2;
    
    if(sscanf(rank,"%s��%s��%s",s1,s2,s3)!=3) return rank;
    len=14-sizeof(s2);
    if(len<1) return rank;

    len1=len/2;
    len2=len-len1;
    if(len1) s2=repeat_string(" ",len1)+s2;
    if(len2) s2+=repeat_string(" ",len2);
    
    return s1+"��"+s2+"��"+s3;
}

string _query_rank(object ob)
{
        string at;
        int dx, exp, avg;
        string rank;

        if(strlen(ob->query("added_title"))<1) ob->set("added_title", "����");
        //need this default, otherwise looks too ugly sometimes.

        at = ob->query("added_title");
        dx = (int)ob->query("daoxing");
        exp = (int)ob->query("combat_exp");
        avg = (dx + exp)/2;

        if( ob->is_ghost() ) return HIB "�� ��  �� ��" NOR;
        if(ob->query("env/rank") && wizardp(ob)) return ob->query("env/rank");
        if (metep(ob))
        {
             if (rank = ob->query("rank"))
             return COLOR_D->get_color(rank) + "��" + filter_color(rank) + "��" NOR;
        }
if (wizardp(ob)) {
    if (ob->query("gender") == "Ů��") return HIW "������Ů��" NOR;
    else return HIW "���������ɡ�" NOR;
}
        switch(ob->query("gender")) 
        {
        case "Ů��":
                                switch(ob->query("class")) 
                                {
//------------------rank for girls--------------------
case "sanjie":
if ( ob->query("family/family_name") == "����ɽ" )
        if(dx<1000) 
                return HIR "�� Сħ�� ��" NOR;
        else if(dx<10000) 
                return HIR "�� ������ ��" NOR;
        else if(dx<500000) 
                return HIR "�� ħ���� ��" NOR;
        else if(dx<1000000) 
                return HIR "��"+at+"��ħ����" NOR;
        else 
                return HIR "��"+at+"�޼�ħ��" NOR;
        break;          

case "swordsman":
        if(dx<1000) 
                return HIC "�� Ů��ͯ ��" NOR;
        else if(dx<10000) 
                return HIC "�� Ů��ʿ ��" NOR;
        else if(dx<500000) 
                return HIC "�� Ů���� ��" NOR;
        else if(dx<1000000) 
                return HIC "��"+at+"���ɡ�" NOR;
        else 
                return HIC "��"+at+"��ʥ��" NOR;
        break;
case "xian":
        if(dx<1000) 
                return HIM "�� ��  Ů ��" NOR;
        else if(dx<10000) 
                return HIM "�� С��Ů ��" NOR;  
        else if(dx<100000) 
                return HIM "�� ��  Ů ��" NOR;
        else if(dx<500000) 
                return HIM "��"+at+"������" NOR;        
 else if ( ob->query("family/family_name") == "��ׯ��" )
       return HIC "��"+at+"���ɡ�" NOR;
   else
                return HIM "��"+at+"���" NOR;
        break;
case "yaomo":

if ( ob->query("family/family_name") == "��ԯ��Ĺ" )
        if(avg<1000) 
                return MAG "�� С���� ��" NOR;
        else if(avg<10000) 
                return MAG "�� ���꾫 ��" NOR;  
        else if(avg<100000) 
                return MAG "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return MAG "��"+at+"������" NOR;        
        else 
                return MAG "��"+at+"��ĸ��" NOR;

if ( ob->query("family/family_name") == "��˿��" )
        if(avg<1000) 
                return MAG "�� С��Ů ��" NOR;
        else if(avg<10000) 
                return MAG "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return MAG "�� Ů  ħ ��" NOR;
        else if(avg<500000) 
                return MAG "��"+at+"ħŮ��" NOR;        
        else 
                return MAG "��"+at+"Ůħ����" NOR;
if ( ob->query("family/family_name") == "���ƶ�" )
        if(avg<1000) 
                return RED "�� С���� ��" NOR;
        else if(avg<10000) 
                return RED "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return RED "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return RED "��"+at+"ħŮ��" NOR;        
        else 
                return RED "��"+at+"��������" NOR;
if ( ob->query("family/family_name") == "��ѩɽ" )
        
                if(avg<1000) 
                return HIW "�� С��Ů ��" NOR;
        else if(avg<10000) 
                return HIW "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return HIW "�� Ů  ħ ��" NOR;
        else if(avg<500000) 
                return HIW "��"+at+"ħŮ��" NOR;        
        else 
                return HIW "��"+at+"Ůħ����" NOR;

if ( ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" )
                if(avg<1000) 
                return YEL "�� С��Ů ��" NOR;
        else if(avg<10000) 
                return YEL "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return YEL "�� Ů  ħ ��" NOR;
        else if(avg<500000) 
                return YEL "��"+at+"ħŮ��" NOR;        
        else 
                return YEL "��"+at+"Ůħ����" NOR;

        break;
case "bonze":           
        if(dx<1000) 
                return HIY "�� С��� ��" NOR;
        else if(dx<10000) 
                return HIY "�� Сʦ̫ ��" NOR;  
        else if(dx<100000) 
                return HIY "�� ʥ  �� ��" NOR;
        else if(dx<500000) 
                return HIY "��"+at+"���᡿" NOR;        
        else 
                return HIY "��"+at+"������" NOR;
        break;
case "taoist":                     
        if(dx<1000) 
                return HIG "�� Ů��ͯ ��" NOR;
        else if(dx<10000) 
                return HIG "�� С���� ��" NOR;  
        else if(dx<100000) 
                return HIG "�� ��  Ů ��" NOR;
        else if(dx<500000) 
                return HIG "��"+at+"��Ů��" NOR;        
        else 
                return HIG "��"+at+"ʥĸ��" NOR;
        break;
case "dragon":          
        if(avg<1000) 
                return HIC "�� С���� ��" NOR;
        else if(avg<10000) 
                return HIC "�� ĸҹ�� ��" NOR;  
        else if(avg<100000) 
                return HIC "�� С��Ů ��" NOR;
        else if(avg<500000) 
                return HIC "��"+at+"��Ů��" NOR;        
        else 
                return HIC "��"+at+"������" NOR;
        break;
case "scholar":
        if( (string)at=="δ��" )
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return GRN "�� Ůѧͯ ��" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return GRN "�� ��  Ů ��" NOR;
                else 
                        return GRN "�� Ůѧʿ ��" NOR;
        }
        else
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return GRN "�� Ůѧͯ ��" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return GRN "��"+at+"��š�" NOR;
                else 
                        return GRN "��"+at+"ѧʿ��" NOR;
        }
        break;
case "fighter":         
        if(exp<1000) 
                return HIR "�� Ů  �� ��" NOR;
        else if(exp<10000) 
                return HIR "�� Ů�ν� ��" NOR;  
        else if(exp<100000) 
                return HIR "�� Ů���� ��" NOR;
        else if(exp<500000) 
                return HIR "��"+at+"�󽫾���" NOR;      
        else 
                return HIR "��"+at+"��Ԫ˧��" NOR;
        break;
case "youling": 
        if(avg<1000) 
                return HIB "������С��" NOR;
        else if(avg<10000) 
                return HIB "���Ի�Ů��" NOR;  
        else if(avg<100000) 
                return HIB "����ڤŮʹ��" NOR;
        else if(avg<500000) 
                return HIB "��"+at+"���ޡ�" NOR;        
        else 
                return HIB "��"+at+"Ů����" NOR;
        break;  
case "dancer":
        return GRN "�� ��  �� ��" NOR;  
        break;
default:                        
        return  HIM "��������Ů��" NOR;
//------------------end rank for girls--------------------
                        }
//begin ���ԣ�
        default:
                                switch(ob->query("class")) 
                                {
//------------------rank for men--------------------
case "sanjie":
if ( ob->query("family/family_name") == "����ɽ" )
        if(dx<1000) 
                return HIR "�� ��ɢ�� ��" NOR;
        else if(dx<10000) 
                return HIR "�� ��ʥ�� ��" NOR;
        else if(dx<500000) 
                return HIR "�� �桡�� ��" NOR;
        else if(dx<1000000) 
                return HIR "��"+at+"����ħ��" NOR;
        else 
                return HIR "��"+at+"Ԫ��" NOR;

case "swordsman":
        if(dx<1000) 
                return HIC "�� ��  ͯ ��" NOR;
        else if(dx<10000) 
                return HIC "�� ��  ʿ ��" NOR;
        else if(dx<100000) 
                return HIC "�� ��  �� ��" NOR;
        else if(dx<500000) 
                return HIC "��"+at+"���ɡ�" NOR;
        else 
                return HIC "��"+at+"��ʥ��" NOR;
        break;
case "xian":                    
        if(dx<1000) 
                return RED "�� ��  ͯ ��" NOR;
        else if(dx<10000) 
                return RED "�� ɢ  �� ��" NOR;  
        else if(dx<100000) 
                return RED "�� ��  �� ��" NOR;
        else if(dx<500000) 
                return RED "��"+at+"���ɡ�" NOR;        
        else if(dx<1000000) 
                return RED "��"+at+"�����" NOR;
        else 
                return RED "��"+at+"����" NOR;
        break;
case "yaomo":
if ( ob->query("family/family_name") == "��ԯ��Ĺ" )
        if(avg<1000) 
                return MAG "�� ��  �� ��" NOR;
        else if(avg<10000) 
                return MAG "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return MAG "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return MAG "�� "+at+"���� ��" NOR;      
        else if(avg<1000000) 
                return MAG "��"+at+"������" NOR;
        else 
                return MAG "��"+at+"������" NOR;

if ( ob->query("family/family_name") == "���ƶ�" )
        if(avg<1000) 
                return RED "�� С  �� ��" NOR;
        else if(avg<10000) 
                return RED "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return RED "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return RED "�� "+at+"�� ��" NOR;        
        else if(avg<1000000) 
                return RED "��"+at+"��ħ��" NOR;
        else 
                return RED "��"+at+"��ħ����" NOR;
        if ( ob->query("family/family_name") == "��˿��" )
        if(avg<1000) 
                return MAG "�� С  �� ��" NOR;
        else if(avg<10000) 
                return MAG "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return MAG "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return MAG "�� "+at+"�� ��" NOR;        
        else if(avg<1000000) 
                return MAG "��"+at+"ħͷ��" NOR;
        else 
                return MAG "��"+at+"��ħ����" NOR;
 if ( ob->query("family/family_name") == "��ѩɽ" )

                if(avg<1000) 
                return HIW "�� С  �� ��" NOR;
        else if(avg<10000) 
                return HIW "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return HIW "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return HIW "�� "+at+"�� ��" NOR;        
        else if(avg<1000000) 
                return HIW "��"+at+"��ħ��" NOR;
        else 
                return HIW "��"+at+"��ħ����" NOR;
 if ( ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" )

                if(avg<1000) 
                return YEL "�� С  �� ��" NOR;
        else if(avg<10000) 
                return YEL "�� ��  �� ��" NOR;  
        else if(avg<100000) 
                return YEL "�� ��  �� ��" NOR;
        else if(avg<500000) 
                return YEL "�� "+at+"�� ��" NOR;        
        else if(avg<1000000) 
                return YEL "��"+at+"�ϻ�ħ��" NOR;
        else 
                return YEL "��"+at+"��ħ����" NOR;

        break;
case "bonze":           
        if(dx<1000) 
                return HIY "�� С���� ��" NOR;
        else if(dx<10000) 
                return HIY "�� ��  �� ��" NOR;  
        else if(dx<100000) 
                return HIY "�� ʥ  ɮ ��" NOR;
        else if(dx<500000) 
                return HIY "��"+at+"��ʦ��" NOR;        
        else if(dx<1000000) 
                return HIY "��"+at+"���ϡ�" NOR;
        else 
                return HIY "��"+at+"��" NOR;
        break;
case "taoist":                      
        if(dx<1000) 
                return HIG "�� С��ʿ ��" NOR;
        else if(dx<10000) 
                return HIG "�� ��  ʿ ��" NOR;  
        else if(dx<100000) 
                return HIG "�� ��  �� ��" NOR;
        else if(dx<500000) 
                return HIG "��"+at+"��ʦ��" NOR;        
        else if(dx<1000000) 
                return HIG "��"+at+"���ˡ�" NOR;
        else 
                return HIG "��"+at+"��ʦ��" NOR;
        break;
case "dragon":          
        if(avg<1000) 
                return HIC "�� Ϻ  �� ��" NOR;
        else if(avg<10000) 
                return HIC "�� з  �� ��" NOR;  
        else if(avg<100000) 
                return HIC "��Ѳ��ҹ�桿" NOR;
        else if(avg<500000) 
                return HIC "��"+at+"ҹ�桿" NOR;        
        else if(avg<1000000) 
                return HIC "��"+at+"����" NOR;
        else 
                return HIC "��"+at+"������" NOR;
        break;
case "scholar":
        if( (string)at=="����" )
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return RED "�� ͯ  �� ��" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return RED "�� ��  �� ��" NOR;
                else 
                        return RED "�� ��ѧʿ ��" NOR;
        }
        else
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return RED "�� ͯ  �� ��" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return RED "��"+at+"��š�" NOR;
                else 
                        return RED "��"+at+"ѧʿ��" NOR;
        }
        break;
case "fighter":         
        if(exp<1000) 
                return HIR "�� С  �� ��" NOR;
        else if(exp<10000) 
                return HIR "�� С  У ��" NOR;  
        else if(exp<100000) 
                return HIR "�� ��  �� ��" NOR;
        else if(exp<500000) 
                return HIR "��"+at+"������" NOR;        
        else if(exp<1000000) 
                return HIR "��"+at+"�󽫾���" NOR;
        else 
                return HIR "��"+at+"��Ԫ˧��" NOR;
        break;
case "youling": 
        if(avg<1000) 
                return HIB "������С��" NOR;
        else if(avg<10000) 
                return HIB "������ʹ�ߡ�" NOR;  
        else if(avg<100000) 
                return HIB "���ظ��й١�" NOR;
        else if(avg<500000) 
                return HIB "��"+at+"�޳���" NOR;        
        else if(avg<1000000) 
                return HIB "��"+at+"����" NOR;
        else 
                return HIB "��"+at+"ڤ����" NOR;
        break;
default:
        return "���������꡿";
//------------------end rank for men--------------------
                        }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "Ů��":
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 18 ) return "Сʦ̫";
        else return "ʦ̫";
        break;
case "taoist":
        if( age < 18 ) return "С�ɹ�";
        else return "�ɹ�";
        break;
case "xian":
        if( age < 18 ) return "С�ɹ�";
        else return "�ɹ�";
        break;
default:
        if( age < 18 ) return "С����";
        else if( age < 50 ) return "����";
        else return "����";
        break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) 
                        {
case "xian":
        if( age < 18 ) return "С����";
        else if( age < 50 ) return "����";
        else return "������";
        break;
case "bonze":
        if( age < 18 ) return "Сʦ��";
        else if( age < 50 ) return "��ʦ";
        else return "����";
        break;
case "taoist":
        if( age < 18 ) return "С��ү";
        else if( age < 50 ) return "����";
        else return "����";
        break;
case "fighter":
        if( age < 18 ) return "С����";
        else if( age < 50 ) return "�󽫾�";
        else return "�Ͻ���";
        break;
case "scholar":
        if( age < 18 ) return "С�๫";
        else if( age < 50 ) return "�๫";
        else return "������";
        break;
case "swordsman":
        if( age < 18 ) return "С�ϵ�";
        else if( age < 50 ) return "׳ʿ";
        else return "��ǰ��";
        break;
default:
        if( age < 18 ) return "С�ֵ�";
        else if( age < 50 ) return "׳ʿ";
        else return "��ү��";
        break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "Ů��":
                        switch(ob->query("class")) 
                        {
case "xian":
        if(age < 30) return "С����";
        else if(age < 50) return "��Ů";
        else return "������";
        break;
case "yaomo":
        if(age < 30) return "С��Ů";
        else if(age < 50) return "��Ů";
        else return "������";
        break;
case "bonze":
        if(age < 30) return "С����";
        else if(age < 50) return "����";
        else return "������";
        break;
case "taoist":
        if(age < 30) return "С��Ů";
        else if(age < 50) return "��Ů";
        else return "������";
        break;
default:
        if( age < 30 ) return "С����";
        else if(age < 50) return "����";
        else return "����̫��";
        break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) 
                        {
case "xian":
        if( age < 50 ) return "������";
        else return "������";
        break;
case "yaomo":
        if( age < 50 ) return "������";
        else return "������";
        break;
case "bonze":
        if( age < 50 ) return "��ͺ¿";
        else return "��ͺ¿";
        break;
case "taoist":
        return "��ţ����";
        break;
case "scholar":
        if( age < 18 ) return "С�����";
        else if( age < 50 ) return "�������";
        else return "��ͯ��";
        break;
default:
        if( age < 18 ) return "С���˵�";
        else if( age < 50 ) return "����";
        else return "��ƥ��";
        break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "Ů��":
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "ƶ��";
        else return "����";
        break;
default:
        if( age < 30 ) return "СŮ��";
        else return "���";
        break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "ƶɮ";
        else return "����";
        break;
case "taoist":
        return "ƶ��";
        break;
case "scholar":
        if( age < 30 ) return "����";
        else return "����";
        break;
default:
        if( age < 50 ) return "����";
        else return "��ͷ��";
        break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "Ů��":
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "ƶ��";
        else return "����";
        break;
default:
        if( age < 50 ) return "������";
        else return "����";
        break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "�������";
        else return "�Ϻ�����";
        break;
case "taoist":
        return "��ɽ��";
        break;
case "scholar":
        if( age < 50 ) return "���๫";
        else return "�Ϸ�����";
        break;
default:
        if( age < 18 ) return "���Сү��";
        else if( age < 50 ) return "��ү��";
        else return "��үү��";
        break;
                        }
        }
}
string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }


        return "����rankd.c -> query_self_close()\n";
}

string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "Ů��" :
                if (userp(ob) && getuid(ob) == this_player()->query("couple/id"))
                    return "����";
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (userp(ob) && getuid(ob) == this_player()->query("couple/id"))
                    return "�Ϲ�";
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}
string imud_query_self_close(object ob,int age,string gender)
{
        int a1, a2;
        if (objectp(ob))
        {
                a1=ob->query("age");
                a2=age;
        } 
        else 
        {       
                a1 = this_player()->query("age");
                a2 = 0;
        }
        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }
}
string imud_query_close(object ob,int age,string gender)
{
        int a1, a2;

        if (objectp(ob))
        {
                a1=ob->query("age");
                a2=age;
        } else 
        {       
                a1 = this_player()->query("age");
                a2 = 0;
        }
                                                        
        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}


