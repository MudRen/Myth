inherit EQUIP;

void create()
{
  set_name("ϸ����¨", ({ "zhu lou","zhulou","lou","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "����һֻƯ����ϸ����¨��\n");
    set("value", 200);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N����ϸ����¨�����ɵر������ϡ�\n");
  set("unequip_msg", "$N��ϸ����¨�ӱ���ж���������ڻ��\n");
}

