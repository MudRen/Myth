
inherit NPC;
#include <ansi.h>
#include <greeting.h>
string ask_girl(object me);
int done_girl();

void create()
{
        set_name("����Ѫħ", ({ "blood king", "xuemo", "king" }) );
        set("gender", "����");
        set("age", 99);
        set("long","�������������磬�����Ϊ�е�����Ѫħ��\n");
        set("combat_exp", 90000000);
        set("title", HIR"�޷�����"NOR);
        set("nickname", HIY"�������"NOR);
        set("attitude", "friendly");
        set("per", 40);
        set("str", 40);
        set("max_kee", 50000);
        set("max_gin", 50000);
        set("max_mana", 60000);
        set("mana", 60000);
        set("force", 60000);
        set("max_force", 60000);
        set("force_factor", 500);
        set_skill("spear", 380);
        set_skill("unarmed", 380);
        set_skill("moyun-shou", 380);
        set_skill("parry", 380);
        set_skill("dodge", 380);
        set_skill("huoyun-qiang", 380);
        set_skill("moshenbu", 380);
        set_skill("spells", 380);
        set_skill("pingtian-dafa", 380);
        map_skill("spear", "huoyun-qiang");
        map_skill("parry", "huoyun-qiang");
        map_skill("dodge", "moshenbu");
        map_skill("unarmed", "moyun-shou");
        map_skill("spells", "pingtian-dafa");
        set("inquiry", ([
                "����" : (: ask_girl :),
                "cancel" : (: done_girl :),
                "fangqi" : (: done_girl :),
                ]));
        setup();

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
        greeting2(this_player());
}

int accept_fight(object me)
{
        command("say ��ƾ�㣡�ߣ����´��������㴵���ˣ�");
        return 0;
}


string ask_girl(object me)
{
    me=this_player();
    if ( me->query("bellicosity") < 1300 )
        return ("�ߺߣ�����Ϊ������������ô��");
    if ( me->query("combat_exp") < 300000 )
        return ("��̫���ˣ������ĺܲҵģ�");
    if ( me->query("girl") == 0 )
        return "/d/obj/girl"->query_yao(me);
}

int accept_object(object who, object ob)
{
      int i;
 string bname = who->query("girl/name");
     
     if ( (string)ob->query("name") != bname )
        return notify_fail("����Ѫħŭ�����㾹�Һ�Ū�ң�\n");
        
     if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("����Ѫħ��ŭ��������ɱ��Ҳ������,С���ұ��㣡\n");
                i =who->query("combat_exp");
      who->add("bellicosity", 10);
      if (i< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
      else { 
      who->add("daoxing", 5000);
 }
      who->add("potential", 50 + random(100) );
      command("smile");
      command("touch " + who->query("id"));
      tell_object(who,"����Ѫħ���ͷ������Ӧ�ý�����\n");
      message("channel:rumor",HIY+"���Ҿ���御�ĳ�ˣ���˵"+who->query("name")+"��"+who->query("girl/name")+"�׸�����Ѫħ��"+who->query("girl/name")+"����Ѫħ���\n"+NOR,users());
      who->delete("girl");
      return 1;
}

int done_girl()
{
        object who = this_player();
        if ( who->query("girl") == 0 )
        {
                tell_object(who,"������û�����񰡡�\n");
                return 1;
        }
        command("qi");
        command("hummar" + who->query("id"));
        tell_object(who,"����Ѫħ�����ӿ����������ģ������ˣ���û�á�\n");
        who->delete("girl");
        return 1;
}


