//xiaozuanfeng.c

int ask_name(); 

inherit F_VENDOR_SALE;
// inherit NPC;
void create()
{
        object yaopai;

	set_name("С���", ({"xiao zuanfeng", "xiao yao", "xiaoyao", "yao"}));
	set("gender", "����" );
	set("age", 16);
        set("title", "��ѩɽѲɽС��");
	set("long", "ȥѩɽ·�ϵ�һ��С������������ͭ�������߱�ߺ�ȡ�\n");
	set("class", "yaomo");
	set("combat_exp", 5000);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 10);

	set("per", 11);
	set("max_kee", 150);

        set("vendor_goods", ([
                "yinzhen": "/d/obj/weapon/throwing/yinzhen",
                "jiudou": "/d/xueshan/obj/jiudou",
                "peijian": "/d/obj/weapon/sword/peijian",
        ]) );


	setup();
	carry_object("/d/obj/armor/shoupi")->wear();

        yaopai=carry_object("/d/xueshan/obj/yaopai");
        yaopai->move(this_object());
        yaopai->set("long","\n  
              ��������������������
              ����������Ⱥħ������
              ��������������������

��              ��ѩɽѲɽʹ�ߣ�С���\n");

       set("inquiry", ([
                "name"     : (:ask_name:),
                "here"     : "�ⶼ��֪���������������������Ǵ�ѩɽ����",
                "ѩɽ"     : "��ѩɽ�����Ҽң�������λ���������б�����Ҫ��Ҫȥ������",
                "�����"     : "�ҼҴ������ͨ��󣬱��¸�ǿ����һ������ʮ�������",
                "������"     : "�ҼҶ�����������ɣ��Բ�ü�������ۣ�"
                          +"���������ⵣ��������������������������"
                          +"ֻ��һ���Ӿ�ȥ����������ͭ��Ҳ�ͻ�����ɥ��",
                "������"     : "�Ҽ��������Ƿ���֮������Ƴ����������ֽд���������"
                          +"�ж�ʱ�������Ӻ�����ͼ�ϡ�",
         ]) );

        set("chat_msg", ({
            "С�������ͭ��ߺ�ȵ���Ѳɽ�ģ����ڵ�ע���ˣ��⼸����ɮ��Ҫ���������Ҷ�������\n",
            "С��纰������ɮ�Ĵ�ͽ������ռ������������׹���\n",
            "С��纰������ɮ�Ķ�ͽ����˽��ͷ�����������⣡\n",
            "С��纰������ɮ����ͽ��ɳ��������������������㾫��\n",
  (: random_move :),
        }) );
        set("chat_chance", 25);
}

void init()
{
   add_action("do_vendor_list", "list");
}


int ask_name() {
  this_object()->command("shutup xiao zuanfeng");  
  return 1;
}

