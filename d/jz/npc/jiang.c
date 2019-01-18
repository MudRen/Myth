//Cracked by Roath
inherit NPC;
#include <ansi.h>
string ask_fish();
string ask_bingfa();

void create()
{
  set_name("��̫��", ({ "jiang taigong","jiang"}));
  set("long", "�������Ǹ�����Ľ�̫����\n");
  set("gender", "����");
  set("age", 57);
  set("str", 50);
  set("max_kee", 1200);
  set("max_sen", 1200);
  set("force", 3000);
  set("max_force", 2000);
  set("force_factor", 60);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 60);
  set("combat_exp", 1500000);
	set("daoxing",1500000)	
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("force", 150);
  set_skill("spells", 150);
  set_skill("unarmed", 150);
  set_skill("staff", 150);
  set_skill("gouhunshu", 150);
  set_skill("tonsillit", 150);
  set_skill("ghost-steps", 150);
  set_skill("jienan-zhi", 150);
  set_skill("lunhui-zhang", 150);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance", 10);
  set("inquiry", ([
        "����" : (: ask_fish :),
        "fish" : (: ask_fish :),
        "����" : (: ask_bingfa :),
        ]));
  set("chat_msg", ({
                "��̫��˵����Ը���Ϲ�...Ը���Ϲ���\n",
                        }));
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
   carry_object("/d/jz/obj/yugan");  
}
string ask_fish()
{
        object ob = this_player();
        object me = this_object();

           if( ob->query("combat_exp") < 1000000 ||
            ob->query("office_number") < 300 )
                return "û�������ڵ�����\n";

        command("hehe");
        ob->set_temp("just_wait",time());
        return "��Ȼ"+ RANK_D->query_respect(ob)
        +"�Ե�������ڣ��ɷ����Ϸ�����㣿\n";
}

string ask_bingfa()
{
        object ob = this_player();
        object book = new("/d/obj/book/bingfa");

        if( ! ob->query_temp("just_wait") )
                return "��������ʲô��\n";

        if( time() - ob->query_temp("just_wait") < 60*60*8 )
                return "��˵ʲô������ô��̫����\n";

        book->set("owner",ob->query("id") );
        book->move(ob);
        return "��Ȼ�г��ģ��Ȿ������ȥ�ж��ж��ɡ�\n";
}
