// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit NPC;

void create()
{
   set_name("����ɮ", ({ "seng" }));
   set("long", "һλ�����ɮ�ˣ��������Ǵ��������Ц�ݡ�\n�������ڴ�ӭ��ǰ����������Ŀ��ˡ�\n");
   set("gender", "����");
   set("age", 25);
   set("attitude", "peaceful");
   set("class", "bonze");
   set("max_kee", 200);
   set("max_gin", 200);
   set("max_sen", 200);
   set("force", 100);
   set("max_force", 100);
   set("force_factor", 10);
   set("max_mana", 100);
   set("mana", 100);
   set("mana_factor", 10);
   set("combat_exp", 5000);
   set_skill("literate", 20);
   set_skill("unarmed", 25);
   set_skill("dodge", 20);
   set_skill("parry", 25);
   set_skill("force", 10);
   set_skill("spells", 10);
   set_skill("buddhism", 10);
   set_skill("unarmed", 30);
   map_skill("spells", "buddhism");
   
   setup();
   add_money("silver", 20);
   carry_object("/d/nanhai/obj/sengpao")->wear();
}
