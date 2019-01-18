// modified by vikee 2000.11
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "gui wang", "wang" }));
        set("title", "");
        set("age", 300);
        set("attitude", "aggressive");
        set("str", 40);
        set("per", 20);
        set("con", 30);
        set("cor", 30);
        
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 60);
        set("combat_exp", 800000);
        set("daoxing", 1000000);

        set_skill("spells",120);
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("unarmed", 120);
        set_skill("zixia-shengong", 120);
        set_skill("sevensteps", 120);
        set_skill("dao",120);
        set_skill("hunyuan-zhang",120);
        map_skill("spells", "dao");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "hunyuan-zhang");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :),
        }) );
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/d/obj/cloth/jinjinyi")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", CYN"\n������������ԭ���ң���Ϊ�������������ΪֻҪ�ܳԾŰپ�ʮ�Ÿ�����\n����һ�ٸ�����Ϳ��Գ�ȥ������...��\n", environment());
        message("sound", "\n�����ֵ������������ϣ��ҷ�����ϣ����ϣ�����ܹ��������뿪�����...ǰ��������鷳�Ļ����������ң���\n", environment());
        message("sound", "\n������ʧ����Ӱ����...\n"NOR, environment());
        }
        destruct(this_object());
}
