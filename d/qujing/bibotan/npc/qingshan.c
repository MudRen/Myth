inherit NPC;

void create()
{
        set_name("Ц������", ({"xiaoboer tian", "tian"}));
        set("long", "������ʯɽ�̲�̶��С����\n");
        set("age", 30);
	set("title", "������");
        set("attitude", "friendly");
        set("gender", "����");
	set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",1000);
        set("max_sen", 1000);
        set("combat_exp", 350000);
  set("daoxing", 450000);

        set("force", 1600);
        set("max_force", 1600);
        set("mana",400);
        set("max_mana", 700);
        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("spells", 120);
        set_skill("dodge", 120);
	set_skill("fork", 120);
	set_skill("parry", 120);
	set_skill("yueya-chan", 100);
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
set("inquiry", ([
"��԰": "��˵���԰�Ǹ������󣬲�֪����λ�ģ��ٺ٣�����\n",
]) );

        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
	if( random(5) > 3  ) {
        if (objectp(present("xiao", environment(this_object())))) {
                switch( random(6) ){
                        case 0:
                                command("say �첨��Ц������˯���ˣ�");
                                command("wake xiao");
                        break;
                        case 1:
                                command("say �첨��Ц����˵�����������ˡ�");
                                command("consider xiao");
                        break;
                        case 2:
                                command("say �첨��Ц�������أ�");
                                command("poke xiao");
                        break;
                        case 3:
                                command("say �첨��Ц�����������Ǹ�С������Ư����");
                                command("grin xiao");
                        break;
                        case 4:
                                command("say �첨��Ц���������ţ����������ȥ��");
                                command("kick xiao");
                        break; 
			case 5:
				command("say �첨��Ц����ȥ������ʾ��λ��");
				command("lazy xiao");
			break;
                	}
        	}
        }
	}
        return ::heal_up() + 1;
}

�