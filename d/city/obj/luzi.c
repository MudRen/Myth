//Last modified by waiwai@2001/04/15
 
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
  set_name("��ҩ¯", ({ "zhiyao lu","luzi"}) );
  set_weight(500);
  set_max_encumbrance(20000);
  set_max_items(20);
  if( clonep() ){
    object ash;
    seteuid(getuid());
   if( ash=new("/d/city/obj/ash") )
      ash->move(this_object());
    set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "���Ǹ�������ҩ��¯�ӡ�\n");
    set("value", 2000);
    set("no_get",1);
  }
  init_hammer(1);
}

int is_container() { return 1; }

void init()
{
        object me=this_object();
        object ob=this_player();
        object *inv;
        int i;
        if( environment(me)->query("done") )
        {
           inv = all_inventory(me); 
           for(i=0; i<sizeof(inv); i++)
            {
              destruct(inv[i]);
              environment(me)->delete("done");
            }
        tell_room(environment(me),HIW"ҩ¯����ɢ����һ�ִ̱ǵ�ζ����\n"NOR);

         }
}
