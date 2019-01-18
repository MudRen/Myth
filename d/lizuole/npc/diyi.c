// �����硤���μ�
/* �����ֱ���99.08.31 */
//diyi.c
 
inherit NPC;
//string apply_gongming(object me);
void do_drink();

void create()
{
        set_name("��һ��", ({"diyi ren", "ren", "diyi"}));
        set("gender", "����");
        set("age", 23); //����
        set("title", "����");
        set("str", 500);
        set("int", 300);
        set("long", "��һ���������ִ����ĵ�һ��npc\n");
        set("combat_exp", 30000000);
        set("attitude", "friendly"); //״̬,(�Ѻ�)\heroism (Ӣ������)\peaceful (��ƽ��)
        set("class", "scholar"); //�ȼ�,(ѧ��)\xian (��)\
      
        create_family("��ħ��", 1, "��ʼ��"); //����
        set_skill("unarmed", 500);
        set_skill("dodge",500);
        set_skill("literate", 1000);
        set_skill("parry", 500);
        set_skill("wuxing-quan", 60);
        set_skill("baguazhen", 70);
        set_skill("hammer", 90);
        set_skill("kaishan-chui", 100);
        set_skill("force", 70);   
        set_skill("zhenyuan-force", 70);
        set_skill("spells", 80);
        set_skill("taiyi", 80);
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("unarmed", "wuxing-quan");
        map_skill("hammer", "kaishan-chui");
        map_skill("dodge", "baguazhen");


        set("force", 5000); 
        set("max_force", 5000);
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 1000);
        set("mana", 1600);
        set("max_mana", 800);   
        set("force_factor", 40);
        set("mana_factor", 40);
   
        set("inquiry", ([
            "name" : "��������ҳ�...���±��ǵ�һ�ˣ�ʵ�������ҵ���\n",
            "here" : "������ǲ�񷡣\n",
           ]) ); //����ask
        
        set("chat_chance",20); //chat żȻ��
        set("chat_msg", ({
        "��һ�˵�����������Σ¥�߰ٳߣ��ֿ�ժ�ǳ���\n",
        "��һ�˵����������������ǧ�꣬�����غ�ͨ���̡�\n",
        "��һ�˹ĸ����裺��������ȥ��������������\n",

        "��һ�˻��ڶ��裺�Կ��Ϻ�ӧ���⹳˪ѩ���������հ����������ǡ�\n",
        (: do_drink :),
        "��һ�˵�������������ߣ�����֮���á������ߣ��ٴ�֮���͡�\n",

        "��һ�˻��ڶ��裺����л���죬��������ݡ���ڼ����գ��������켦��\n",
        "��һ���������·�ԶӰ�̿վ���Ψ�������������\n",
        "��һ���������������֮�ѣ����������죬������������ൡ�\n",
        (: do_drink :),
        "��һ�˵������������������ᣬ���������ơ�\n",
        "��һ����̬��¶������������������ñ���谮�����ˡ�\n",
        "��һ�˳���������������������գ��������ڡ�\n",
        (: random_move :) //����ƶ�
        //(: random_walk :), �����
        }));   
        
        set("maolu", 0); //ë¿
        setup();
        carry_object("/d/obj/cloth/choupao")->wear(); //����
        carry_object("/d/obj/weapon/sword/changjian")->wield(); //����
        carry_object("/d/obj/book/poem"); //��Ʒ
        add_money("silver", 40); //Ǯ
}

void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say �ƣ��������Ҿƣ�����");
    }
    return;
}
