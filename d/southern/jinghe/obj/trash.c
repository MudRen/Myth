//Cracked by Roath
// ajax  06/14/99

inherit ITEM;


string *names = ({
  "ˮ��",
  "��ѥ��",
  "����",
  "�з��",
});

string *units = ({
  "��",
  "ֻ",
  "��",
  "��",
});


void create()
{
   int i;
   i=random(sizeof(names));
   set_name(names[i], ({"fei pin"}));
   set("unit", units[i]);
   set_weight(100);
   if( clonep() )
           set_default_object(__FILE__);
   else 
     {
     set("long","һ�ѳ���ˮ�׶���ķ��\n");
     }
   setup();
}


