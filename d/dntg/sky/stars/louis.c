//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("����",({"star louis","louis","star"}));
  set("gender", "����");
  set("title", "�����ǹ�");
  set("age", 57);
  set ("long", @LONG
���Ǹ��������ˣ��к��·��������ʹ���;û�к��·��������ʹ��Ƶġ��кþƺ�������
���ͳ�;û�еóԣ������������ҹ����Ҳ���ں���
�������������ҹ�������ǻ�Ц���������˿���������������ʱ�򡣡�
����������Ц����Ц�ú���㣬��ʱ������������Ц����ʱ�������۾���Ц����ʱ��
��������СŮ��һ������������Ц��

����Ц���У����Կ�������һ������⣬��û�����ּ�̵ļ�ڽ��
��������������Ц�����Ӿ����ѿ���
LONG);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1897251);
  set("daoxing", 1897251);
  set("kee", 1231);
  set("max_kee", 1231);
  set("sen", 2307);
  set("max_sen", 2307);
  set("force", 5465);
  set("max_force", 2733);
  set("mana", 9459);
  set("max_mana", 4730);
  set("force_factor", 149);
  set("mana_factor", 237);
  set("str", 24);
  set("per", 21);


  set_skill("buddhism", 34);
  set_skill("cuixin-zhang", 79);
  set_skill("dao", 11);
  set_skill("dodge", 198);
  set_skill("force", 199);
  set_skill("ghost-steps", 151);
  set_skill("jindouyun", 246);
  set_skill("kusang-bang", 142);
  set_skill("literate", 139);
  set_skill("parry", 156);
  set_skill("puti-zhi", 17);
  set_skill("qianjun-bang", 267);
  set_skill("spells", 254);
  set_skill("stick", 188);
  set_skill("unarmed", 138);
  set_skill("wuxiangforce", 200);
  set_skill("yaofa", 253);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "cuixin-zhang");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/shoes")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="shoes";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"��ɫ������"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"��ɫ��װ"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"��ɫƤѥ"NOR);
}

