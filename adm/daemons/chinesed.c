// chinesed.c

#include <localtime.h>

#define DICTIONARY DATA_DIR + "static/chinese"

inherit F_SAVE;

nosave string *c_digit = ({ "��","ʮ","��","ǧ","��","��","��" });
nosave string *c_num = ({"��","һ","��","��","��","��","��","��","��","��","ʮ"});
nosave string *sym_tian = ({ "��","��","��","��","��","��","��","��","��","��" });
nosave string *sym_di = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });


mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
        seteuid(getuid());
        restore();
}

void remove() { save(); }

string chinese_number(int i)
{
        if( i<0 ) return "��" + chinese_number(-i);
        if( i<11 ) return c_num[i];
        if( i<20 ) return c_num[10] + c_num[i-10];
        if( i<100 ) {
                if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
                else return c_num[i/10] + c_digit[1];
        }
        if( i<1000 ) {
                if( i%100==0 )
                        return c_num[i/100] + c_digit[2];
                else if( i%100 < 10 )
                        return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
                else if( i%100 < 20 )
                        return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
                else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
        }
        if( i<10000 ) {
                if( i%1000==0 )
                        return c_num[i/1000] + c_digit[3];
                else if( i%1000 < 100 )
                        return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
                else
                        return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
        }
        if( i<100000000 ) {
                if( i%10000==0 )
                        return chinese_number(i/10000) + c_digit[4];
                else if( i%10000 < 1000 )
                        return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
                else
                        return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
        }
        if( i<1000000000000 ) {
                if( i%100000000==0 )
                        return chinese_number(i/100000000) + c_digit[5];
                else if( i%100000000 < 10000000 )
                        return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
                else
                        return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
        }
                if( i%1000000000000==0 )
                        return chinese_number(i/1000000000000) + c_digit[6];
                else if( i%1000000000000 < 100000000000 )
                        return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
                else
                        return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
}

string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun
string chinese(string str)
{
        if (!undefinedp(dict[str])) return dict[str];
        else return str;
}

void remove_translate( string key )
{
        map_delete( dict, key );
        save();
}

void add_translate( string key, string chinz )
{
        dict[key] = chinz;
        save();
}

void dump_translate()
{
        string *k, str;
        int i;

        str = "";
        k = keys(dict);
        for(i=0; i<sizeof(k); i++)
                str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
        write_file("/CHINESE_DUMP", str);
}

// this function translate time to chinese
// mudring Sep/09/2002
string chinese_time(int time)
{
        int t, d, h, m, s, y;
        string ret;
        
        t = time;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t % 30;             t /= 30;
        y = t;

        if (y) ret = chinese_number(y) + "��";
        else ret = "";

        if (d) ret += chinese_number(d) + "��";
        if (h) ret += chinese_number(h) + "ʱ";
        if (m) ret += chinese_number(m) + "��";
        ret += chinese_number(m) + "��";

        return ret;
}

string chinese_date(int date)
{
        mixed *local;

        if (date <= 0) date = 1;
        local = NATURE_D->query_localtime(date);

        return sprintf("%s%s��%s��%s��%sʱ%s��",
                sym_tian[local[LT_YEAR] % 10], sym_di[local[LT_YEAR] % 12],
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY] + (local[LT_HOUR] > 23 ? 1 : 0)),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
                chinese_number((local[LT_MIN] + 1) % 2 * 2 + 
                local[LT_MIN] / 30 + 1) );
}

//Used in natured.c to as a condition to judge which season should be
//to use different weather discription.
string chinese_month(int date)
{
        return chinese_number(NATURE_D->query_month());
}

string chinese_monthday(int date)
{
        mixed *local;
        local = NATURE_D->query_localtime(date);
        return sprintf("%s��%s��",
                       chinese_number(local[LT_MON] + 1),
                       chinese_number(local[LT_MDAY]));
}

//end of appendance

// ����ִ��Ƿ�����
int is_chinese(string str)
{
        int i;

        if (strlen(str) < 2) return 0;

        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] < 161 || str[i] == 255) return 0;
                if (! (i % 2) && (str[i] < 176 || str[i] >= 248)) return 0;
        }

        return 1;
}

// moved this function here
// mudring Sep/09/2002
string chinese_daoxing(int gain)
{            
        int year, day, hour;
        string str;

        year = gain / 1000;
        day  = (gain - year * 1000) / 4;
        hour = (gain - year * 1000 - day * 4) * 3;
        str  = "";
        if (year) str = str + chinese_number(year) + "��";
        if (day)  str = str + chinese_number(day) + "��";
        if (hour) str = str + chinese_number(hour) + "ʱ��";

        return str;
}


