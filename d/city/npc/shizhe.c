#include <ansi.h>
#include <mudlib.h>
inherit NPC;
string ask_me();
int ask_cake();
void create()
{
         set_name( "����������ʹ" , ({ "liwu shi","shi zhe","shi" }) );

        set("color", HIG);
        set("gender", "����");
        set("age", 19);
        set("per",40);
        set("attitude", "peaceful");
        set("inquiry", ([
                 "��������" : (: ask_cake :),  
        ]));
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
int ask_cake()
{ 
        object ob;
        if (this_player()->query("birth"))    {
            command("say ��ϲ��ϲ��ף�����տ��֣�\n");
          ob=new("/d/city/npc/obj/cake");  //�����·�����Զ��塣
          ob->set("owner",this_player()->query("id"));
          ob->move(this_player()); 
          message_vision("\n$N����$nһ�����Ƶ����յ��⡣\n",  this_object(),this_player());
          this_player()->delete("birth"); 
         return 1;            }
      return 0;
}
