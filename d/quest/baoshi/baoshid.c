// File��/quest/baoshi.c 
// Changed to heart_beat() by mudring@sjsh...... 
 
#include <ansi.h> 
 
inherit F_DBASE; 
int random_place(string dirss,object bs); 
 
string *dirs = ({ 
"/d/changan", 
"/d/city", 
"/d/eastway", 
"/d/gao", 
"/d/lingtai", 
"/d/moon", 
"/d/nanhai", 
"/d/sea", 
"/d/westway", 
"/d/qujing/wuzhuang", 
"/d/ourhome/honglou", 
"/d/death", 
"/d/penglai", 
"/d/xueshan", 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan", 
"/d/qujing/biqiu", 
"/d/qujing/chechi", 
"/d/qujing/dudi", 
"/d/qujing/fengxian", 
"/d/qujing/firemount", 
"/d/qujing/jilei", 
"/d/qujing/jindou", 
"/d/qujing/jingjiling", 
"/d/qujing/jinping", 
"/d/qujing/jisaiguo", 
"/d/qujing/maoying", 
"/d/qujing/nuerguo", 
"/d/qujing/pansi", 
"/d/qujing/pingding", 
"/d/qujing/qilin", 
"/d/qujing/qinfa", 
"/d/qujing/qinglong", 
"/d/qujing/tianzhu", 
"/d/qujing/tongtian", 
"/d/qujing/wudidong", 
"/d/qujing/wuji", 
"/d/qujing/xiaoxitian", 
"/d/qujing/yinwu", 
"/d/qujing/yuhua", 
"/d/qujing/zhujie", 
"/d/qujing/zhuzi", 
}); 
 
string *dirname = ({ 
"������", 
"��������", 
"�����Ƕ�", 
"����ׯ", 
"��̨����ɽ", 
"�¹�", 
"�Ϻ�����ɽ", 
"��������", 
"��������", 
"��ׯ��", 
"��¥һ��", 
"���޵ظ�", 
"�����ɵ�", 
"��ѩɽ", 
"��ͷɽ", 
"�����", 
"�̲�̶", 
"�����", 
"���ٹ�", 
"����ɽ", 
"���ɿ�", 
"����ɽ", 
"����ɽ", 
"��ɽ", 
"������", 
"��ƽ��", 
"������", 
"ëӱɽ", 
"Ů����", 
"��˿��", 
"ƽ��ɽ", 
"����ɽ", 
"�շ���", 
"����ɽ", 
"���ù�", 
"ͨ���", 
"�޵׶�", 
"�ڼ���", 
"С����", 
"����ɽ", 
"����", 
"���ɽ", 
"���Ϲ�", 
}); 
 
void create() 
{ 
        seteuid(getuid()); 
        set("channel_id", "��ʯ����"); 
} 
 
void choose_baoshi() 
{ 
        int i, j ,k,ppl,rd; 
        object *list,newob; 
        string str,m_name; 
        string smp; 
         
        j = random(sizeof(dirs)); 
        rd = random(6);  
      
          
                newob = new(__DIR__"baoshi");
                 str = "��"; 
        
        reset_eval_cost(); 
                 
        if(random_place(dirs[j],newob)== 1 )
        message_job( HIR"�����챦��"+HIW"ͻȻ���д��˸�ը��,һ�������ճ���,����һ��"+str+"����"+dirname[j]+"�ķ�����ȥ��"); 
        if(newob->query("b_lvl")>14)
        message_job( HIR"�����챦��"+newob->name()+"���ٷ��䣡"); 
        return ; 
} 
 
int random_place(string dirss,object bs) 
{ 
        int  j, k; 
        object  newob,ob; 
        mixed*  file, exit; 
        string id_name; 
        file = get_dir( dirss+"/npc/*.c", -1 ); 
         
        if( !sizeof(file) ) return 0; 
 
        for(k=0;k<50;k++) { // try 50 times 
           j = random(sizeof(file)); 
           if( file[j][1] > 0 ) { 
             newob=load_object(dirss+"/npc/"+file[j][0]); 
             if(!newob) continue; 
             id_name = newob->query("id"); 
             destruct(newob); 
             if(!id_name) continue; 
             if(!objectp(ob=find_living(id_name))) continue; //���npc���ǻ��  
                     if(bs->move(ob)) { 
                    CHANNEL_D->do_channel( this_object(), "sys", "��ʯ�䵽��"+ob->query("name")+"("+ob->query("id")+")�����ϡ�");  
                     return 1; 
                    } 
             } 
           } 
         CHANNEL_D->do_channel( this_object(), "sys", "���α�ʯ����ʧ��"); 
        return 0; 
} 

