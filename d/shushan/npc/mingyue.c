//Cracked by Roath
//����ɽ���ɡ�koker 2001.3.10
inherit NPC;

void create()
{
        set_name("����", ({ "ming yue", "yue" }));
        set("long", 
"��������ɽ��������һ���Ķ����˲š�\n");
        set("gender", "Ů��");
        set("age", 26);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 23);
        set("con", 24);
        set("cor", 22);
        set("class","swordsman");
        
        set("max_kee", 1500);
        set("max_sen", 1500);
        set("force", 3000);
        set("max_force", 1500);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);

        set_skill("force", 100);
        set_skill("zixia-shengong", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("taoism", 110);
        set_skill("unarmed", 100);
        set_skill("whip", 180);
        set_skill("spells", 110);
        set_skill("sevensteps", 110);
        set_skill("hunyuan-zhang", 100);
        set_skill("yujianshu", 120);
        set_skill("yirubian", 180);
        set_skill("literate", 100);

        map_skill("force", "zixia-shengong");
        map_skill("dodge", "sevensteps");
        map_skill("spells", "taoism");
        map_skill("unarmed", "hunyuan-zhang");

        create_family("��ɽ����", 6, "����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "powerup" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name") == "��ɽ����" && ob->query("family/generation") < 7){
                command("say " + RANK_D->query_respect(ob) + "��Ҫ����Ц��");
                return; 
        }
        if ((int)ob->query_cor() < 15) {
                command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ϣ�");
                return;
        }
        if ((string)ob->query("race") == "����" || (string)ob->query("race") == "����") {
                command("say ���¿�ʲô��Ц������ô�ܹ�����ħ֮ͽΪͽ�أ�");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
}
