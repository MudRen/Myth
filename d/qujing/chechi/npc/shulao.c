// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("˵����", ({"shuoshu lao", "lao"}) );
  set("gender", "����" );
  set("age", 55);
  set("long","һλ�������ӵ����ˣ�������ľ˵�顣\n");

  set("combat_exp", 5500);
  set("str", 25);
  set("attitude","heroism");

  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", 2);
}

void init()
{
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}

void says (object me)
{
  string *msgs = ({
    "$N��ž��������һ�¾���ľ��\n",
    "$N������ɫ��˵��ʲô��\n",
    "$N���ϲ�����˵���顣\n",
    "$N˵��ü��ɫ�衣\n",
    "$N���˸����ӣ�ͣ�²�˵�ˡ�\n",
    "$N��������˼���ˮ����˵���ˡ�\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
  call_out("says",random(40),me);
}

