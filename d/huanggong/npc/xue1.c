
inherit NPC;
#include <ansi.h>
#include <greeting.h>
string ask_bad(object me);

void create()
{
        set_name("Ѧ�ʹ�", ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "����");
        set("age", 35);
        set("long","Ѧ�ʹ��ǳ����Ǿ����ᶽ������ʹ����ⰲȫ��\n");
        set("combat_exp", 350000);
        set("title", HIR"�����ᶽ"NOR);
        set("nickname", HIY"�¹�����"NOR);
        set("attitude", "friendly");
        set("per", 25);
        set("str", 35);
        set("max_kee", 850);
        set("max_gin", 600);
        set("max_mana", 500);
        set("mana", 500);
        set("force", 600);
        set("max_force", 600);
        set("force_factor", 35);
        set_skill("spear", 80);
        set_skill("unarmed", 80);
        set_skill("changquan", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("bawang-qiang", 70);
        set_skill("yanxing-steps", 70);
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
        set("inquiry", ([
            "�ӷ�": (: ask_bad :),
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
        command("say ��Ϊ��ǰ���������������Ұƥ����գ�");
        return 0;
}


string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 300 )
        return ("�������ʹ�ݡ�");
    if(me->query("combat_exp") < 100000 )
        return ("����ô�ܷ�����ȥ�أ�");
    return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
                int i;
      string bname = who->name()+"��"+who->query("bad/name") + "��ͷ­";
     
write(bname+"\n",environment(who), who);
write(ob->query("killer")+"\n",environment(who), who);
     if ( (string)ob->query("name") != bname )
        return notify_fail("Ѧ�ʹ�ŭ�����㾹�Һ�Ū�ң�\n");
        
//if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
//       return notify_fail("Ѧ�ʹ��ŭ��������ɱ��Ҳ������,С���ұ��㣡\n");
                i =who->query("combat_exp");
      who->add("office_number", 1);
      if (i< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
        else { 
        who->add("combat_exp", 1501);
 }
      who->add("potential", 50 + random(100) );
      command("smile");
          command("touch " + who->query("id"));
      tell_object(who,"Ѧ�ʹ���ͷ������Ӧ�ý�����\n");
message("channel:chat",HIY+"�������쳯��Ѧ�ʹ�(Xue rengui)��"+who->query("name")+"ɱ����"+who->query("bad/name")+"������һ�ȡ�\n"+NOR,users());
      who->delete("bad");
      return 1;
}
