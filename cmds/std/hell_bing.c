
//jjf_bing.c...Weiqi 12/12/97.
//command to let jjf people get qin bing.

inherit F_CLEAN_UP;
 
int find_allbing(string str);
int find_mybing(object me, string str, int show_position);

int main(object me, string arg)
{
	string QINBING_FILE = "/obj/npc/qinbing.c";
	object qinbing;
	int max_bing = 0;
	int current_bing = 0;

	seteuid(getuid());

/*
	if (!wizardp(me))
		return notify_fail("�����У�Ŀǰֻ����ʦ���á�\n");
*/

	if( arg == "find" )
	{//let wiz find all qinbing copies.
		if (!wizardp(me))
			return notify_fail("ֻ����ʦ���������ѡ�\n");
		else return find_allbing(QINBING_FILE);
	}	

	if( (string)me->query("family/family_name") != "���޵ظ�" )
    		return notify_fail("�㲢�ǵظ���������쵼���䣿\n");
	
	if(me->query("combat_exp") >= 500000)
	{
		max_bing = 4;
	}
	else if(me->query("combat_exp") >= 100000)
	{
		max_bing = 2;
	}
	else if(me->query("combat_exp") >= 50000)
	{
		max_bing = 1;
	}
	else max_bing = 0;

	if( max_bing < 1 ) 
    		return notify_fail("��Ŀǰ��û���ʸ����ױ���\n");

	current_bing = find_mybing(me, QINBING_FILE, 0);
	//last 0 means do not show position.

	me->set_temp("jjf_current_bing", current_bing+1);

	if( (int)me-> query_temp("jjf_current_bing") > max_bing )
		return notify_fail("����ļ���в�������Ĺ����ˡ�\n");

	//ready to get qin bing out...btw, let the player pay first.
	//1 gold each qin bing.
	if( (int)me->query("balance") < 10000)
	{
		return notify_fail("�������Ѿ������������ˣ�˭�����㣿\n");
	}
	//ok, the player has enough money...
	me->set("balance",  (int)me->query("balance")-10000);
	me->save();

	//now let's get the qing bing out.
	message_vision("ֻ��$N���һ������������\n", me);
	qinbing = new(QINBING_FILE);
	qinbing->move(environment(me));
	qinbing->show(me);

    	return 1;
}
 
int find_allbing(string str)
{
	object *list;
	int number;
	object where;
	int i, count;
	
	count = 0;

	if(!str) return 0;

	list = children(str);
	number = sizeof(list);

	if(number) 
	{
		for(i=0; i<sizeof(list); i++) 
		{
			write((int)(i+1)+". "+file_name(list[i])+" "+
				list[i]->query("name")+"("+list[i]->query("id")+") is at ");
			where=environment(list[i]);
			if(where) 
			{
				if(where->query("short")) 
				{
					write(where->query("short"));
				} 
				else 
				{
					write(where->short());
				}
				write("("+file_name(where)+"), " );
				write("owner_id: " + list[i]->query("owner_id") + "\n");
			} 
			else 
			{
				write("???, ");
				write("owner_id: " + list[i]->query("owner_id") + "\n");
			}
		}
	}
	
	count = number;
	write("\n����" + count + "���ױ���\n");
	return count;
}

int find_mybing(object me, string str, int show_position)
{
	object *list;
	int number;
	object where;
	int i, count;
	
	count = 0;

	if(!str) return 0;

	list = children(str);
	number = sizeof(list);

	if(number) 
	{
		for(i=0; i<sizeof(list); i++) 
		{
			if( (string)list[i]->query("owner_id") != (string)me->query("id") )
				continue;
			count++;
			if(!show_position) continue;

			//now also show position.
			write(list[i]->query("name")+"��");
			where=environment(list[i]);
			if(where) 
			{
				if(where->query("short")) 
				{
					write(where->query("short"));
				} 
				else 
				{
					write(where->short());
				}
				write("\n");
			} 
			else 
			{
				write("������");
				write("\n");
			}
		}
	}
	
	return count;
}


int help(object me)
{
    write(@HELP
ָ���ʽ: jjf_bing (��ʦ����jjf_bing find) 
 
��͢�佫�����ױ���Ϊ����������磬��������ڸ��佫֮����
��Ȼ��ν�������ò��С���û��Ǯ�ױ�Ҳ�����ˡ�
����whisper���ױ���������磬�������ױ���ttt-jia����
whisper ttt-jia kill xiao er����������ɱ��С����

HELP
    );
	return 1;
}
 
