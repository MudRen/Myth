//sgzl

inherit NPC;

void create()
{
set_name("��ͯ",({"yun tong","yun shen","tong"}));
set("gender", "����");
set("age", 15);
set("long", "    \n�칬�и������Ƶ��������俴��ȥ������ᣬȴ\n�ƹ����������е��Ʋʡ�\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 800000);
  set("daoxing", 80000);


  

set("kee", 500);
set("max_kee", 500);
set("sen", 550);
set("max_sen", 550);
set("force", 700);
set("max_force", 700);
set("mana", 900);
set("max_mana", 900);
set("force_factor", 20);
set("mana_factor", 30);
set("per", 22);


set_skill("dodge", 80);
set_skill("jindouyun", 50);
set_skill("unarmed", 70);
set_skill("puti-zhi", 70);
set_skill("spells", 90);
set_skill("parry", 90);


map_skill("dodge", "jindouyun");
map_skill("unarmed", "puti-zhi");
set("inquiry", ([
  "����"   : "��������������ƣ����Ҳ��ܸ��㡣",
  "cloud"   : "��������������ƣ����Ҳ��ܸ��㡣",
  "name"   : "��������",
  "here"   : "��������칬��",
]));


setup();

carry_object("/d/obj/cloth/xianpao")->wear();
carry_object("/d/dntg/sky/obj/yunlingfu");

}
���
