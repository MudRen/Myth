#include <ansi.h>
inherit NPC;
inherit F_SAVE;
int give_lllll();
void create()
{
      set_name("�����������", ({"wushi dashen","wushi"}));
      set ("long", @LONG
���������︺�����ҷ���������ģ���ҸϿ�����Ҫ��ask���ɡ�
LONG);
        set("gender", "����");
        set("title",HIY"��ӭ���������񻰳ɶ�վ"NOR);
        set("age", 20);
        set("max_kee", 10000);
        set("kee", 10000);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([           
            "��������"  :(:give_lllll:),  
                         ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
        
}
string query_save_file()
{
        return DATA_DIR+"gift_temp";

}
int give_lllll()
{       
        object who;
        mapping skill;
        string *skillnames,*ips,ipp;
        int i;
        who=this_player();
//
        if (!userp(who)){
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
        if(who->is_busy())
           {               
            tell_object(who,"����æ���أ�\n");
                return 1;
            }
       if (this_player()->query("lll/gai") != "got" )
           {
             message_vision("$N����$n˵��������Ҳ��Ҫ��\n",this_object(),this_player());
           return 1;
            }     
       if (this_player()->query("lll/skills") != "got" )
           {
              message_vision("$N����$n˵��������Ҳ��Ҫ��\n",this_object(),this_player());
              return 1;
            }
        if (this_player()->query("age")<15 )
           {
              message_vision("$N����$n˵��������Ҳ��Ҫ��\n",this_object(),this_player());
              return 1;
            }
         if (this_player()->query("combat_exp")<150000 )
           {
              message_vision("$N����$n˵��������Ҳ��Ҫ��\n",this_object(),this_player());
              return 1;
            }
         if (this_player()->query("lll/xngift") == "got" ){
               message_vision("$N����$n����һ����\n",this_object(),this_player());
               command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
               return 1;
                } 

                        who->add("combat_exp",200000);
                        who->add("daoxing",400000);
                        who->add("force",200);
                        who->add("mana",200);
                        who->add("maximum_force",100);
                        who->add("max_mana",100);
                        who->add("max_force",100);
                        who->add("maximum_mana",100);
//                        who->add("balance",500000);
                        who->add("potential",88888);
                        who->set("lll/xngift","got");
                        save();
                        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ����������");
                        command("say ��ϲ��ϲ��"+who->query("name")+"�õ����������");
                       return 1;

}


