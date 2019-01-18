// �������� "��ҶĦ�� ����" by Calvin

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIY"������ʦ"NOR, ({"master qixin","qixin","qi","xin" ,"tianshen","master"}));
       set("long", "�������ҶĦ�������շ����,���������������ǰ��һ��֮ʦ\n");
       set("title", HIY"��ҶĦ��"NOR);
       set("gender", "����");
       set("age", 100);
        set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�����");
       set("per", 40);
       set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
       set("int", 35);
       set("max_gin", 1000);
       set("max_kee", 10000);
       set("force", 13000);
       set("max_sen", 10000);
       set("force_factor", 250);
       set("max_force", 4500);
       set("max_mana", 4500);
        set("daoxing", 35000000);
       set("mana", 13000);
       set("mana_factor", 250);
       set("combat_exp", 10000000);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("parry", 350);
        set_skill("stick", 350);
        set_skill("sword", 350);
        set_skill("liangyi-sword", 350);
        set_skill("spells", 350);
        set_skill("dao", 350);
        set_skill("puti-zhi", 350);
        set_skill("wuxiangforce", 350);
        set_skill("force", 350);
        set_skill("qianjun-bang", 350);
        set_skill("jindouyun", 350);
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

        carry_object("/d/9ct/zb/zhua")->wield();
        carry_object("/d/9ct/zb/stick")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
        if ((int)ob->query("daoxing") < 2000000 ) {
        command("say ����," + RANK_D->query_respect(ob) + "�������������\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�������Ž���ͨ����,���з����޳�������,�������ղ�������!\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 38) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }

        if( (int)ob->query_skill("dao", 1) < 220 ) {
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
        if( (string)ob->query("gender") == "Ů��" )
                ob->set("title", HIC"����ɽ����ʥĸ"NOR);
        else
                ob->set("title", HIC"����ɽ��������"NOR);
}

