inherit EQUIP;

void create()
{
  set_name("�̻�����", ({ "zhu lan","zhulan","lan","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "����һֻƯ�����̻�������\n");
    set("value", 200);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N�����̻����������ɵر������ϡ�\n");
  set("unequip_msg", "$N���̻������ӱ���ж���������ڻ��\n");
}

