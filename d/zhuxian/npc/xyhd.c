#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIY "�Ƶ�" NOR, ({"huang di", "huang", "di"}));
    set("title", HIR "��ԯ" NOR);
    set("long", "���Ҷ�����ʶ��\n");
    set("gender", "����");
    set("age", 13500);
    set("str", 40);
    set("per", 40);
    set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 10000);
    set("eff_sen", 10000);
    set("max_kee", 10000);
    set("max_sen", 10000);
    set("sen", 10000);
    set("kee", 10000);
    set("max_force", 10000);
    set("max_mana", 10000);
    set("mana", 10000);
    set("force", 20000);
    set("force_factor",  500);
    set("mana_factor", 500);
    set_skill("seashentong", 301 );
    set_skill("dragonforce", 301 );
    set_skill("zixia-shengong", 301 );
    set_skill("taoism", 301 );
    set_skill("lengquan-force", 301 );
    set_skill("baguazhou", 301 );
    set_skill("gouhunshu", 301 );
    set_skill("tonsillit", 301 );
    set_skill("spear", 321 );
    set_skill("bawang-qiang", 321 );
    set_skill("mace", 301 );
    set_skill("axe", 301 );
    set_skill("sword", 301 );
    set_skill("hammer", 301 );
    set_skill("fork", 301 );
    set_skill("stick", 301 );
    set_skill("whip", 301 );
    set_skill("unarmed", 301 );
    set_skill("spells", 301 );
    set_skill("force", 301 );
    set_skill("dodge", 301 );
    set_skill("parry", 301 );
      map_skill("force", "dragonforce");
      map_skill("spells", "taoism");
      map_skill("spear", "bawang-qiang");

    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: cast_spell, "fu" :),
        (: cast_spell, "jianshen" :),
(: exert_function, "roar" :),
(: exert_function, "shield" :),
}));
      setup();
   
}

int accept_fight(object me)
{
        write(CYN "�Ƶ�����ͷ�����룬˵�����ðɡ�\n" NOR);
        return 1;
}

int recognize_apprentice(object me)
{
      object ob = this_player();
      
      if (!(int)ob->query_temp("mark/��"))
             return notify_fail( HIR "�������Ƶ���ɱ���㣡\n"NOR);
        if( ( ob->query("family/family_name") != "������"
            && ob->query("family/family_name") != "��ɽ����"
            && ob->query("family/family_name") != "���޵ظ�"
            && ob->query("family/family_name") != "��������")
            || ob->query("combat_exp")  < 2000000 ) 
             return notify_fail( HIR "�������Ƶ���ɱ���㣡\n"NOR);
        ob->add_temp("mark/��", -1);
             return 1;
}
