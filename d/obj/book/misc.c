//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
	int i;
        set_name("�����顽", ({"book"}));
        set_weight(500);
        i=random(11);
	if( clonep() ) 
                set_default_object(__FILE__);
        else {
		set("long","һ���ƾɲ�����С���ӡ�\n");
                set("unit", "��");
		set("value", 0);
        	set("material", "paper");
	if( i>=10)
                set("skill", ([
                        "name":"whip",  
                        "sen_cost": 20,  
                        "difficulty": 20,
                        "max_skill": 20,
                ]) );
	else if( i>=9)
        	set("skill", ([
			"name":"axe",
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 20,
		]) );
	else if(i>=8)
		set("skill", ([
                        "name":"blade",
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 20, 
                ]) );
        else if(i>=7)
                set("skill", ([
                        "name":"fork",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else if(i>=6)
                set("skill", ([
                        "name":"hammer",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else if(i>=5)
                set("skill", ([
                        "name":"mace",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else if(i>=4)
                set("skill", ([
                        "name":"rake",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else if(i>=3)
                set("skill", ([
                        "name":"spear",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else if(i>=2)
                set("skill", ([
                        "name":"staff",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else if(i>=1)
                set("skill", ([
                        "name":"stick",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 
        else 
                set("skill", ([
                        "name":"sword",
                        "sen_cost": 20,   
                        "difficulty": 20, 
                        "max_skill": 20,
                ]) ); 

	}
}

void destruct_me(object where, object me)
{
  message_vision("$n��Ϊ���ֽм�����������Ʈȥ�ˡ�\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}
