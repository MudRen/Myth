inherit NPC;
void consider();

void create()
{
        set_name("�ֹ���", ({"lin guanyu", "lin"}));
        set("age", 42);
        set("gender", "����");
        set("long",
"�Ŷ�����ϰ壬Ц���еĿ����㡣\n��Ц�ݵĺ����������һ˿������\n");
	set("title", "�Ŷ����ϰ�");
        set("attitude", "friendly");

        set("combat_exp", 20000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("sen", 300);
	set("max_sen", 300);
	set("force_factor", 10);
        set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("sword", 50);
	set_skill("fonxansword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 40);
	map_skill("unarmed", "changquan");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	setup();
	carry_object("/d/obj/weapon/sword/changjian");
        carry_object("/d/obj/cloth/choupao")->wear();
}
int accept_fight(object me)
{
        command("say �𣬱������ﶫ�����Ǳ����������˿ɲ����ˣ�\n");
        return 0;
}

void consider()
{
        int i, flag = 0;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                        flag++;
		if(     !query_temp("weapon") ) {
                command("say ��Ȼ���±���̫������Ҳ�������������ˣ�\n");
                        command("wield sword");

                        break;
		}
        }
}
