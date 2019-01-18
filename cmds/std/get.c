// get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob, object old_env);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2,old_env;
	int i, amount;
        mixed no_get;

	if( !arg ) return notify_fail("��Ҫ����ʲô������\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
                if(living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
	} else env = environment(me);


	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("����û������������\n");
                no_get = obj->query("no_get");
		if( no_get 
                && !(wizardp(me) && me->query("env/wizset") == "drop") ) {
			return notify_fail(stringp(no_get) ? 
				no_get : "��������ò�������\n");
		}
	
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
		if( amount < 1 )
			return notify_fail("�����ĸ���������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("����û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj,0);
		} else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_get(me,obj2, environment(obj))) {
			    obj->set_amount( (int)obj->query_amount()-amount);
			    return 1;
			}
			return 0;
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if( !env->query_max_encumbrance() )	return notify_fail("�ǲ���������\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("������û���κζ�����\n");

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->is_character() || inv[i]->query("no_get"))
				continue;
			do_get(me, inv[i],0);
		}
		write("Ok��\n");
		return 1;
	}

// added by mon to incorporate the "bian" function.
        if(!objectp(obj= present(arg, env)) || obj==this_player())
	   return notify_fail("�㸽��û������������\n");
        else {
         if((obj->query_temp("d_mana"))>0) {
	  if( obj->query_temp("is_living")==1 )
	    return notify_fail("�㸽��û������������\n");
	  else {
	    no_get = obj->query("no_get");
            if( no_get 
	    && !(wizardp(me) && me->query("env/override")))
                return notify_fail(stringp(no_get) ? no_get : "��������ò�������\n");
            old_env = environment(obj);
	    if( obj->move(me) ) {
                if( me->is_fighting() ) me->start_busy(1);
	    message_vision( sprintf("$N%sһ%s$n��\n",
            old_env==environment(me)?  "����": (old_env->is_character() ?
            "��" + old_env->name() + "����" + "�ѳ�":
            "��" + old_env->name() + "���ó�"),
	    undefinedp(obj->query_temp("unit"))?
	    "��":obj->query_temp("unit")
	    ), me, obj);
	    return 1; 
	    } else return 0;
          }
        } else {
	  if( living(obj) )
		return notify_fail("�㸽��û������������\n");
        }
	}

        no_get = obj->query("no_get"); 
        if( no_get  
	&& !(wizardp(me) && me->query("env/override")))
                return notify_fail(stringp(no_get) ? no_get : "��������ò�������\n");

	return do_get(me, obj,0);
}
	
int do_get(object me, object obj, object old_env)
{
	object *enemy;
	int equipped;
	object* inv;
/*
	inv = all_inventory(me);
	if( sizeof(inv) > 30 )
	   return notify_fail("��������Ҳװ�����κζ����ˡ�\n");
*/
	if( !obj ) return 0;
	if(!old_env) old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
		//	if( !userp(obj) && !obj->is_corpse() )
		//		return notify_fail("��ֻ�ܱ���������ҵ����塣\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	if( obj->query("equipped") ) equipped = 1;
	if( obj->move(me) ) {
		if( me->is_fighting() ) me->start_busy(1);
		if( obj->is_character() )
		  message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
		else
		  message_vision( sprintf("$N%sһ%s$n��\n", 
		  (!old_env || old_env==environment(me))? "����":
		  (old_env->is_character() ?
		  "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
		  "��" + old_env->name() + "���ó�"),
	          undefinedp(obj->query("unit"))?
	          "��":obj->query("unit")
		  ), me, obj );
		  if(obj->query("obj_owner")&&obj->query("obj_owner")!=me->query("id"))
		  { write("���һ��С�� ��"+obj->query("name")+"�������ϵ�����ˤ���˷��飡\n");
		    destruct(obj);
		   }
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]
 
���ָ��������������ϻ������ڵ�ĳ����Ʒ.
 
HELP
    );
    return 1;
}
 
