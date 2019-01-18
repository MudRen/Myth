// by bluewww@yszz

#include <ansi.h>

inherit F_SAVE;

mapping shili=([
"baoxiang": (["���޵ظ�":1000,]),
"biqiu"   : (["�Ϻ�����ɽ":1000,]),
"qinfa"   : (["��ׯ��"    :1000,]),
"chechi"  : (["����ɽ���Ƕ�":1000,]),
"fengxian": (["��������": 1000,]),
"jinping" : (["��ɽ����"  : 1000,]),
"jisaiguo": (["���޵ظ�": 1000,]),
"nuerguo" : (["�¹�"    : 1000,]),
"tianzhu" : (["��ѩɽ"  : 1000,]),
"tongtian": (["��������": 1000,]),
"wuji"    : (["��ׯ��"  : 1000,]),
"yuhua"   : (["��ѩɽ"  : 1000,]),
"wudidong": (["�ݿ�ɽ�޵׶�" : 1000,]),
"zhuzi"   : (["��ԯ��Ĺ"     : 1000,]),
]);

mapping MASTERS=(["����ɽ���Ƕ�":"��������", 
                 "�Ϻ�����ɽ":"��������",
                 "��ׯ��":"��Ԫ����",
                 "���޵ظ�":"������",
                 "�¹�":"�϶�",
                 "��������":"����",
                 "��ѩɽ":"��������",
                 "�ݿ�ɽ�޵׶�":"����",
                 "��ɽ����":"��ʥ",
                 "��ԯ��Ĺ":"槼�",                                
]);

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(shili) ){
        shili = ([]);
    }
}

int remove()
{
    save();
    return 1;
}        

string query_save_file() { return DATA_DIR + "shilid"; }         

string query_family(string pos)
{
        mapping tmp;
        string* nf;
        int max,i=1,nmax;
        
        if(!mapp(tmp=shili[pos]))return "";
        nf=keys(tmp);
        max=tmp[nf[0]];
        nmax=0;
        
        while(i<sizeof(nf)){
           if(tmp[nf[i]]>max){
                max=tmp[nf[i]];
                nmax=i;
           }
           i++;
        }
        return nf[nmax];
}

string query_master(string faname)
{
        return MASTERS[faname];
}

int query_shili(string pos,string faname)
{
        mapping tmp;

        if(!mapp(tmp=shili[pos]))return 0;
        return tmp[faname];
}
 // added by happ@YSZZ 

int query_all_shili(string faname)
{
        mapping tmp;
        int i,n;
        string *quyu;

        if( ! mapp(shili) ) return 0;

        quyu=keys(shili);                     
        
        for( i=0;i<sizeof(shili);i++)
        {
         n=query_shili(quyu[i],faname);
        printf("�ڡ�%-s����%6d������",this_object()->query_chinese(quyu[i]),n);  
       i%2==1?write("\n"):write("            ");
        }

 return 1;
}



void increase_shili(string pos,string faname,int amount)
{
        mapping tmp;
        
        if(!mapp(tmp=shili[pos]))return;
        if(!tmp[faname])tmp+=([faname:amount]);
        else tmp[faname]+=amount;
        
        if(tmp[faname]>1000)tmp[faname]=1000;
}

void decrease_shili(string pos,string faname,int amount)
{
        mapping tmp;
        
        if(!mapp(tmp=shili[pos]))return;
        if(!tmp[faname])return;
        else tmp[faname]-=amount;
        
        if(tmp[faname]<0)tmp[faname]=0;
}

string query_chinese(string pos)
{
  mapping diqu=([
     "baoxiang": "�����",
     "biqiu"   : "�����",
     "qinfa"   : "�շ���",
     "chechi"  : "���ٹ�",
     "fengxian": "���ɿ�",
     "jinping" : "��ƽ��",
     "jisaiguo": "������",
     "nuerguo" : "Ů����",
     "tianzhu" : "���ù�",
     "tongtian": "�¼�ׯ",
     "wuji"    : "�ڼ���",
     "yuhua"   : "�񻪸�",
     "wudidong": "�޵׶�",
     "zhuzi"   : "���Ϲ�",
  ]);
 return diqu[pos];
}
 
