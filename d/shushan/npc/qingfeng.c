//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("���", ({ "qing feng", "feng" }));
        set("long", 
"�������ɽ��������һ���Ĵ���ӡ�\n");
        set("gender", "����");
        set("age", 29);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("cor", 28);
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
        set_skill("dodge", 80);
        set_skill("parry", 100);
        set_skill("literate", 100);
        set_skill("sword", 90);
        set_skill("taoism", 100);
        set_skill("unarmed", 90);
        set_skill("hunyuan-zhang", 90);
        set_skill("yujianshu", 90);
        set_skill("spells", 100);
        set_skill("sevensteps", 110);

        map_skill("force", "zixia-shengong");
        map_skill("dodge", "sevensteps");
        map_skill("parry", "shushan-jianfa");
        map_skill("sword", "shushan-jianfa");
        map_skill("unarmed", "hunyuan-zhang");
        map_skill("spells", "taoism");

        create_family("��ɽ����", 6, "����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "powerup" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);

        setup();
        carry_object("/d/obj/cloth/jiuzhouxue")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name") == "��ɽ����" && ob->query("family/generation") < 7){
                command("say " + RANK_D->query_respect(ob) + "��Ҫ����Ц��");
                return; 
        }
        if ((int)ob->query_cor() < 20) {
                command("say ��������Ҫ�൱�ĵ��������ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ϣ�");
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

