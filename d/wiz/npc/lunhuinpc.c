//cigar �ֻ�ת��NPC  
  
#include <ansi.h>  
inherit NPC;  
string ask_for_leave();  
  
void create()  
{  
        set_name(HIW"ת���ֻ�����"NOR, ({"lunhui pusa","pusa"}));  
        set("gender", "Ů��" );  
        set("age", 25);  
        set("title",HIY"����������翣��ա��ޡ���"NOR);  
        set("long", HIG"\n\n������������ƹ�ת���ֻصĴ��ǡ���������\n\n"NOR);  
        set("combat_exp", 1000000000);  
          set("daoxing", 5000);  
  
        set("attitude", "peaceful");  
        set("per", 40);  
        set("max_kee", 20000);  
        set("max_gin", 20000);  
        set("max_sen", 20000);  
        set("inquiry", ([  
                "�ֻ�ת��" : (: ask_for_leave :),  
                "Ͷ̥" : (: ask_for_leave :),  
                ]) );  
        setup();  
        carry_object("/d/ourhome/obj/pink_cloth")->wear();  
        carry_object("/d/ourhome/obj/shoes")->wear();  
}  
  
void init()  
{  
        add_action("do_agree", "agree");  
}  
  
string ask_for_leave()  
{  
        object me=this_player();  
  
      if ((int)me->query("combat_exp") > 900000000 )  
{  
                command("say ���˼�ǹ����ֻ�ת�����ɶ�Ϸ��������Ѿõ��书����з��涼Ҫ������");  
                me->set_temp("c_lunhui", 2);  
                return ("�׺�ɣ��������ң����Ը���������һ�е�һ�У��ƺ쳾�������ң���ʦ���ţ���Ը���(agree)��");  
        }  
  
        return ("������ת���ֻ�����׺�С�ۣ��޼����¡�\n");  
}  
  
int do_agree(string arg)  
{  
        int i,j,level; 
        mapping skill_status; 
        object ob,who; 
        string skill,obj; 
        string *skills; 
         
        who=this_player(); 
        seteuid(getuid());
        if(!who->query_temp("c_lunhui")) {  
                 command("say �������������"); 
                 return 1; 
                 } 
        if(who->query_temp("c_lunhui") > 1 ) {  
                message_vision("$N˵�������쳾�����������ֻ�ת��������һ������������\n\n", ob);  
                command("say ��Ȼ��ˣ������ھ������������������쳾֮��Բ�㳬��֮�⣡");  
         ob =new(USER_OB); 
         
         ob->set("combat_exp",400000);           
         ob->set("daoxing",400000);  
         ob->set("maximum_mana",1500);  
         ob->set("maximum_force",1500);  
         ob->set("mud_age",0);  
         ob->set("class","lunhui");    
         ob->set("lunhui/lunhui",1);    
         
         
              //��������趨ת��֮�������  
  
         ob->set("str",40);  
         ob->set("cor",40);  
         ob->set("int",30);  
         ob->set("spi",40);  
         ob->set("cps",40);  
         ob->set("per",30);  
         ob->set("con",40);  
         ob->set("kar",30);  
  
  
                  
                ob->delete("family");  
                ob->set("title", HIW"ת���ֻ�"+ HIY"����һ��������"NOR);  
                ob->add("lunhui_zhuanshi", 1); 
                ob->add("opinion/mete",1);
                ob->add("balance",10000000);
                ob->add("protential",20000);
                ob->delete_temp("betray");  
                ob->set("startroom","/d/city/kezhan");
                ob->set("id",who->query("id"));
               ob->set("name",who->query("name"));
                command("say �����ڼ���������\n");  
                command("chat ����һ���������㡣��������̥����ʪ��������������ɫ����ɫ�������������롣���������������롣���������缰����˵��\n");  
                command("chat ��Ӧ��ס���ġ���Ӧ��ס�Ƿ��ġ���Ӧ������ס�ġ����Թʡ�������ס��Ϊ��ס�ʡ�\n");  
                command("chat �ֻ�ת���տյ�ȥ��������������һ�ȣ�"+who->query("name")+"�ƺ쳾֮�������׷���Ĺ��ҷ��ֻ�ת���ˡ�\n");  
                 ob->save();  
                 destruct(who);
                 destruct(ob);
                return 1;  
        }  
}  
  
 
 

