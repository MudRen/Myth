#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("������仨ƿ", ({ "hua ping","huaping","ping","vase"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    object a,b;
    seteuid(getuid());
    if(a=new("/d/obj/flower/rose") )
      a->move(this_object());
    seteuid(getuid());
    if(b=new("/d/obj/flower/juhua") ) 
       b->move(this_object()); 
    set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "����һֻ�������Ƶ������仨ƿ��\n");
    set("value", 2000);
  }
  set("wield_msg", "$N����������仨ƿ��С�ĵر����ؿڡ�\n");
  set("unwield_msg", "$N��������仨ƿ����ط��¡�\n");
  init_hammer(1);
}

int is_container() { return 1; }
//int query_autoload() { return 1; }

