//����������

#include <ansi.h>
#include "place.h"
string* guainame=({
        "Ұè��","yemao guai",
        "Ұ����","yeji guai",
        "Ұ����","yegou guai",
        "Ұ�ù�","yetu guai",
        "Ұ���","yexiang guai",
        "Ұ�ܹ�","yexiong guai",
        "Ұ���","yezhu guai",
        "Ы�ӹ�","xiezi guai",
        "Ұ���","yehou guai",
"����","yizi yao",
"����","gui po",
"����","feng yao",
"ѩ��","xue jing",
"����","hama guai",
"�ڻ���","bihu guai",
"ˮ�߾�","shuishe jing",
"��ʬ","jiang shi",
"����","shu yao",
"���꾫","huli jing",
"������","huaishu jing",
"��Ѫ��","xixie gui",
"������","yangshu jing",
"������","diaosi gui",
"���޳�","heiwu chang",
"���޳�","baiwu chang",
"������","hudie jing",
"����","xing tian",
"��","kui",
"���","chi you",
"ˮħ��","shui moshou",
"��ħ��","tu moshou",
"��ħ��","huo moshou",
"�Թ�","jiao guai",
"����","she yao",
"ʯ�����","shiji niangniang",
"��ɽ����","heishan laoyao",
"��򼾫","wugong jing",
"�׹Ǿ�","baigu jing",
"֩�뾫","zhizhu jing",
"����","feng yao",
"������","denglong guai",
"̳�Ӿ�","tanzi guai",
"ɨ�Ѿ�","saoba jing",
});

string* xianname=({
        "����","xian ren",
        "�ɹ�","xian guan",
        "��Ů","xian nu",
        "����","xian qing",
        "�ɽ�","xian jiang",
        "����","xian fei",
        "����","da xian",
        "���ƴ�ʦ","baiyun dashi",
        "�����","yanchi xia",
        "����","xian zi",
        "����ר��","secmieyao zhuanjia",
        "����","pu sa",
        "����","gong gong",
        "ף��","zhu rong",
        "������","jiang ziya",
        "��߸","ne zha",
        "ľ߸","mu zha",
        "��߸","jin zha",
        "��������","tuota tianwang",
        "���","jin gang",
        "����","zun zhe",
        "��Ŵ���","chijiao daxian",
        "�Ʒɻ�","huangfei hu",
        "�����","guancheng zi",
        "̫������","taiyi zhenren",
        "½ѹ����","luya daoren",
        "������","kuilei sheng",
        "��ظ","zhong kui",
        "�޺�","luo han",
        "����","jian xian",
        "����ү","zaowang ye",
        "������","tudi shen",
        "����","cai shen",
        "��Ů","long nv",
        "�Ʋ�ͯ��","shancai tongzi",
        "��������","jinbao tianzun",
        "���","tian bing",
        "�콫","tian jiang",
        "������","juling zhen",
});


int add_new_yao(object me);
string do_task2(object who);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
     int i;
     object who=this_player();
     if (!who->query("menpai_task")
        ||!who->query("menpai_t_time")
        ||(who->query("menpai_t_time")+900 > time() && who->query("menpai_task")))
          {
          who->set("menpai_task",1);
          who->set("menpai_t_time",time());
              if (who->query("menpai_task")==1)
              {
              who->delete_temp("tongchuan");
              who->clear_condition("tongchuan_job");
              who->clear_condition("job_busy");
              }
              if (who->query("menpai_task")==3)
              {
            who->delete_temp("dajiu");  
            who->clear_condition("baohu_job");  
            who->clear_condition("job_busy");  

              }             
          return "/d/quest/xue/xue"->ask_tongchuan(me);
          }

     if (who->query("menpai_task")==99 )
             {
                 if (who->query("combat_exp") < 1800000 ) i=random(2)+1;
                 else i=random(3)+1;
              }
                 else i=who->query("menpai_task");

     who->set("menpai_t_time",time());
      
     if (i==3)  { 
               who->set("menpai_task",3);
               return do_task2(me);
                }

     if (i==1) {
     who->set("menpai_task",1);
     return "/d/quest/xue/xue"->ask_tongchuan(me);}

     if (i==2) {
     who->set("menpai_task",2);
     if(!who->query("m_mieyao"))
      {

       if(who->query("secmieyao_mudage")+480 < time())
        {
                return("��������ȥɱ��"+who->query("secmieyao/place")+"��"+who->query("secmieyao/name")+"ô��\n");
        } else {
                who->set("m_mieyao",1);
                who->add("faith",-1);
                who->add("m_shibai",1);
                return ("������û�ã����ٸ���һ�λ��ᣡ");
                }
      }
      else {
        if(time()-who->query("secmieyao_mudage")<120)
                 return ("�ɵĲ�������ȥ��Ϣ��Ϣ�ɡ�\n");
                 else {
                       who->delete("m_mieyao");
                        add_new_yao(who);
        if(who->query("secmieyao/type")=="xian")
                    {
                            return ("����"+who->query("secmieyao/name")+"("+who->query("secmieyao/id")+")��"+who->query("secmieyao/place")+"Ϊ��������\n������ȥ���������Ծ�������ħ������\n");
                     } else {
                            return ("��˵"+who->query("secmieyao/name")+"("+who->query("secmieyao/id")+")�����"+who->query("secmieyao/place")+"һ�����У�\n������ȥ������������ħ�����ƣ�\n");
                            }
                       }
             }
                }


}


int add_new_yao( object me)
{
    string my_id,my_cls,type;
    string sname;

    string* yaoname;
    int my_exp,index,i;
    mapping skill_status;
    mapping secmieyao;
    object where,yao;

    my_exp=me->query("combat_exp");
    my_cls=me->query("class");

     if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"||my_cls=="fighter"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }

    index=random(sizeof(yaoname)/2)*2;

    secmieyao=(["type" : type]);
    secmieyao+=(["id" : yaoname[index+1] ]);

    if(my_exp<10000)
    {
    sname="СС "+yaoname[index];
    i = 0;
    }
    else if(my_exp<100000)
    {
    sname="ʮ�� "+yaoname[index];
    i = 1;
    }
    else if(my_exp<1000000)
    {
    sname="���� "+yaoname[index];
    i = 2;
     }
    else if(my_exp<10000000)
     {
     i = 3;
    sname="ǧ�� "+yaoname[index];
     }
else
{
sname="�õ� "+yaoname[index];
 i = 4;
}

    secmieyao+=(["name" : sname]);

    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
      my_exp = 0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&(string)SKILL_D(yaoname[index])->type()=="martial")
           my_exp=skill_status[yaoname[index]];
      }
    }

    index=random(sizeof(place))+1;
    yaoname=place[index];
    secmieyao+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    secmieyao+=(["location" : sname]);
    me->set("secmieyao_mudage",time());
    me->set("secmieyao",secmieyao);

    if(!(where=find_object(secmieyao["location"])))
             where=load_object(secmieyao["location"]);

    switch(i)
        {
        case 0:
        yao=new("/d/obj/npc/yao0");
        break;
        case 1:
        yao=new("/d/obj/npc/yao0");
        break;
        case 2:
        yao=new("/d/obj/npc/yao");
        break;
        case 3:
        yao=new("/d/obj/npc/yao1");
        break;
        case 4:
        yao=new("/d/obj/npc/yao1");
        break;
        }
    yao->set("taskguai", 1);
    yao->move(where);
    yaoname=explode(secmieyao["id"]," ");
    yaoname=({secmieyao["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");
    yao->set_name(me->name()+"�� "+secmieyao["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),secmieyao["type"]);
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping secmieyao=me->query("secmieyao");

    if(!mapp(secmieyao))return 0;
    loclist=explode(secmieyao["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&secmieyao["id"]==yaoid);
    return 0;

}


////////////////////////////////////////////

string do_task2(object who)
{
    object me = this_player();
    object guai;
    string where;
    int tt;



    if (me->query_condition("baohu_job"))
    
       return CYN +who->name()+"��ɫһ�����¹������������ж���\n"+NOR;
        
    

    if (me->query_condition("job_busy"))
    {
        if(who->query("class")=="xian"
            ||who->query("class")=="taoist"
            ||who->query("class")=="dragon"
            ||who->query("class")=="bonze"
            ||who->query("class")=="fighter")               
        return who->name()+"��ָһ�㣬����ħ��û�в�ȡʲô�ж�������ల���¡�\n";
        else return who->name()+"��ָһ�㣬�������豾�̻���������ల���¡�\n";
    }

  

    guai = NPC_D->task_npc();
    where = guai->query("place");
    me->delete_temp("dajiu");
    me->set_temp("dajiu/get", 1);
    me->set_temp("dajiu/id", guai->query("id"));
    me->set_temp("dajiu/name", guai->query("name"));
    me->set_temp("dajiu/where", where);
    me->delete_temp("dajiu/kk");
    me->apply_condition("baohu_job", 25); // 5 min
    me->apply_condition("job_busy", 25 + random(10)); // 5 min

    write( CYN +who->name()+"˵����ҹ���������ħ���п��ܶ�" + guai->query("name") +
        "("+ guai->query("id") + ")����������ȥ" + where + "�����䰲ȫ��\n"+NOR);
/*
    this_object()->command("job " + me->name() +
        "�ӵ�һ������" + guai->name() + "������");
*/
    me->command("say ����������");
    me->start_busy(1);
    

    return CYN+who->name()+"˵������ȥ�ٻأ�"+NOR;
}




