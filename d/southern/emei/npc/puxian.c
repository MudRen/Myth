//Cracked by Roath
// wenshu-pusa

// #include <ansi.h>

inherit NPC;
void create()
{

  set_name("��������", ({ "puxian pusa", "pusa", "pu sa", "puxian" }) );
  set("gender", "����" );
  set("long", @LONG

    ���ͣ�Ϊ��̴������֮һ����������ͬΪ���ȷ��в�̡���˵
���������ڻ��Ϸ����Ϸ���ʮ����Ը�����������Ϊ��ʮ��Ը������
������Ը�������˷�̵�������̸�����ǣ��պ�����Ϊʲ���������
����Ի��������֮ѧ����У���֮������Ī���󣬹ʺ��󡣡�
���󣬼���ζ����Ը�й�󣬹���Բ����
    
LONG );
  set("age",55);
  set("title", "��̴������");
  set("attitude", "peaceful");
  set("rank_info/self", "ƶɮ");
  set("class", "bonze");
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 4000);
  set("max_force", 2000);
  set("force_factor", 145);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 150);
  set("combat_exp", 2000000);
  set("daoxing", 10000000);

  set_skill("literate", 150);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 150);
  set_skill("jienan-zhi", 150);
  set_skill("dodge", 180);
  set_skill("lotusmove", 180);
  set_skill("parry", 180);
  set_skill("force", 180);
  set_skill("lotusforce", 180);
  set_skill("staff", 180);
  set_skill("lunhui-zhang", 180);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
          (: cast_spell, "bighammer" :),
    }) );

  setup();
  carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}
	






