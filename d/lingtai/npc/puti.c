//puti.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("������ʦ", ({"master puti","puti", "master"}));
        set("long", "�������û���ˣ���������������\n");
        set("title", HIC"б������"NOR);
        set("gender", "����");
        set("age", 100);
        set("color", HIW);
        set("class", "taoist");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("rank_info/respect", "��ʦ��");
        set("per", 26);
        set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
        set("int", 30);
        set("max_kee", 5000);
        set("max_gin", 1000);
        set("max_sen", 5000);
        set("force", 5000);
        set("max_force", 2500);
        set("force_factor", 150);
        set("max_mana", 2500);
        set("mana", 5000);
        set("mana_factor", 150);
        set("combat_exp", 3000000);
        set("daoxing", 10000000);
        
        set_skill("literate", 200);
        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("stick", 220);
        set_skill("sword", 220);
        set_skill("liangyi-sword", 180);
        set_skill("spells", 220);
        set_skill("dao", 220);
        set_skill("puti-zhi", 180);
        set_skill("wuxiangforce", 220);
        set_skill("force", 220);
        set_skill("qianjun-bang", 180);
        set_skill("jindouyun", 180);
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

        create_family("����ɽ���Ƕ�", 1, "��");
        setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/lingtai/obj/putibang")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
        if ((int)ob->query("daoxing") < 300000 ) {
        command("say ��������֮ʿ���صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����޳����Ϸ�ԭ������Ϊͽ�ˣ�\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 35) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("dao", 1) < 120 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "���ҵ����ɷ���ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "ɱ��̫�أ��ֻ������ѣ�\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n������ʦ΢��üͷ���������˹��Ǹ���ɵؾ͵ģ�\n\n", environment());
        command("sigh");
        message("sound", "\n������ʦ����һת�������������ˡ�����\n\n", environment());
        }

        destruct(this_object());
}

