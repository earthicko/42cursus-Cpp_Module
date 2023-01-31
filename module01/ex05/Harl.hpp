#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:
							Harl(void);
							Harl(const Harl &orig);
							~Harl(void);
		Harl				&operator=(const Harl &orig);

		void				complain(std::string level);
	
	private:
		void				debug(void);
		void				info(void);
		void				warning(void);
		void				error(void);

		const static int	nLoggers = 4;
		static void			(Harl::*loggers[4])(void);
		static std::string	loggernames[4];
};

#endif
