
inherit EQUIP;

void create()
{
  set_name("ϸ�������", ({ "hua lan","hualan","lan","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
	object a,b;
	seteuid(getuid());
	if(a=new("/d/obj/flower/juhua") )
		a->move(this_object());
	seteuid(getuid());
        if(b=new("/d/obj/flower/rose") ) 
                b->move(this_object()); 
    set_default_object(__FILE__);
}  else {
    set("unit", "ֻ");
    set("long", "����һֻ�������ײ��׵񻨶б�ϸ���������\n");
    set("value", 1000);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N����ϸ������������ɵر������ϡ�\n");
  set("unequip_msg", "$N��ϸ��������ӱ���ж���������ڻ��\n");
}

int is_container() { return 1; }
//int query_autoload() { return 1; }

