#include <ansi.h>

inherit ITEM;

void create()
{
         set_name(HIM"����"BLINK+HIW"�ιο�"NOR, ({ "guagua ka","card" }) );
        set("long",
HIW"һ������ιο�(card)�������ι�"HIR"(open)"HIW"������ʲô������!\n"NOR);
        set("unit", "��");
        set("weight", 100);
        set("value", 10000);
//        set("no_get","����Ц�ɣ��ⶫ����Ҳ���������" );
        set("no_give","������˰ɣ���ô���Ҹ��ˣ�" );
//        set("no_drop","��Ҫ����ˣ��ӵ����������" );
        set("no_put","�ٺ١�������ⶫ���������ﰡ��" );
        set("no_sell","С�����뱦������Ŷ��" );
  setup();
}

int init ()  
{   
  add_action ("do_open", "open");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_open (string arg)
{
  string *hows = ({
    "����Ҹ���",
    "��������",
    "��������",
    "�����̵�",
    "��Ϊ�����",
    "������",
    "�����û��������",
    "���������",
    "����������",
    "�������ɵ�",
    "�������ۣ�",
    "ҡͷ���Ե�",
    "����һЦ��",
    "���ֱ��ŵ�",
    "��ͷ���Ե�",
    "�ƿ����ˣ��ںü�ʽ��",
    "�˷ܵ���ͷ�󺹣�",
    "Ĩȥ�۽ǵ��Ứ��",
    "����֣�һ��ţ�",
    "������צ��",
  });

  string *manners = ({
    "��ʼ��Ӳ�ҹ�$n",
  });


  message_vision ("$N"+rdm(hows)+rdm(manners)+"��\n",
                  this_player(),this_object());

      if( arg=="gift card" || arg =="����ιο�" || arg =="gift" || arg =="card" ) 
{
  message_vision ("
���⡫�⡫�⡫�⡫����ϲ��ϲ������ιο���ͻȻ�ĳ�һ���������뱦��
Ц�����Ķ�$N˵������ϲ���������������˵�ն�$N����һЦ��$N����
����������ˡ���������Ľ�Ʒ�ɡ�\n",
                  this_player(),this_object());

this_player()->add("combat_exp",5000);
this_player()->add("daoxing", 5000);
this_player()->add("potential",5000);
this_player()->save();
write(HIR"��Ľ�Ʒ��:\n
      "HIW"������� 5000��Ǳ�� 5000����ѧ \n
      "HIW" ������ȫ����ʦף��"BLINK+HIM"�������\n"NOR,

               environment(this_player()), this_player());
  destruct(this_object());
  return 1;

}
         return 1;
}

